#include <stdio.h>
#include <math.h>

int main (void) {
    int n;
    n = 10;

    long double a;
    long double b;
    long double p;
    long double t;

    long double ans;

    a = 1.0;
    b = 1/sqrt(2);
    p = 1.0;
    t = .25;

    ans = 0.0;
    for (int i = 0; i < n; i++) {
        long double a_new = (a + b) / 2;
        long double b_new = sqrt(a * b);
        long double p_new = 2 * p;
        long double t_new = t - p * pow(a_new - a, 2);

        a = a_new;
        b = b_new;
        p = p_new;
        t = t_new;
    }

    ans = pow(a + b ,2)/(4 * t);

    FILE *fp;
    fp = fopen("ans.txt", "w");
    fprintf(fp, "%.100Lf", ans);
    fclose(fp);

    printf("ans = %.100Lf", ans);
    return 0;
}