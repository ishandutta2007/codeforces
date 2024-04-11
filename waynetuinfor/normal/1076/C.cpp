#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int d; scanf("%d", &d);
        if (d * d - 4 * d < 0) {
            puts("N");
            continue;
        }
        double s = sqrt(d * d - 4 * d);
        double a = (d + s) / 2, b = (d - s) / 2;
        if (b < 0 || a < 0) {
            puts("N");
            continue;
        }
        printf("Y %.20lf %.20lf\n", a, b);
    }
    return 0;
}