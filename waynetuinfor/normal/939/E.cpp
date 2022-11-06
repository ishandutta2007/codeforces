#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
long long s[maxn];

double cal(int n, int m) {
    int a = s[n] - s[n - 1];
    return a - 1.0 * (a + s[m]) / (m + 1);
}

int main() {
    int q; scanf("%d", &q);
    int n = 0;
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x; scanf("%d", &x); ++n;
            s[n] = s[n - 1] + x;
            continue;
        }
        int l = 0, r = n + 1;
        while (r - l > 1) {
            // printf("l = %d, r = %d\n", l, r);
            int m = l + r >> 1;
            // printf("m = %d\n", m);
            // printf("cal(n, m) = %.10f, cal(n, m + 1) = %.10f\n", cal(n, m), cal(n, m + 1));
            if (cal(n, m - 1) >= cal(n, m)) r = m;
            else l = m;
        }
        // printf("l = %d, r = %d\n", l, r);
        printf("%.10f\n", cal(n, l));
    }
    return 0;
}