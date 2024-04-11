#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, inf = 2e9 + 1;
int x[maxn], y[maxn];
int pmax[maxn], pmin[maxn], smax[maxn], smin[maxn];
int n, o[maxn];

bool check(int t) {
    int p = 0;
    for (int i = 0; i < n; ++i) {
        while (p < n && x[o[p]] - x[o[i]] <= t) ++p;
        if (i == 0) {
            if (p == n) return true;
            if (smax[p] - smin[p] <= t) return true;
        } else if (p == n) {
            if (pmax[i - 1] - pmin[i - 1] <= t) return true;
        } else {
            int l = min(pmin[i - 1], smin[p]);
            int r = max(pmax[i - 1], smax[p]);
            if (r - l <= t) return true;
        }
    } 
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        x[i] = a + b, y[i] = a - b;
    }
    iota(o, o + n, 0); sort(o, o + n, [&](const int &i, const int &j) { return x[i] < x[j]; });
    pmax[0] = pmin[0] = y[o[0]];
    for (int i = 1; i < n; ++i) pmax[i] = max(pmax[i - 1], y[o[i]]), pmin[i] = min(pmin[i - 1], y[o[i]]);
    smax[n - 1] = smin[n - 1] = y[o[n - 1]];
    for (int i = n - 2; i >= 0; --i) smax[i] = max(smax[i + 1], y[o[i]]), smin[i] = min(smin[i + 1], y[o[i]]);
    int d = 31, ans = inf;
    while (d--) if (ans - (1 << d) >= 0) if (check(ans - (1 << d))) ans -= (1 << d);
    printf("%.20lf\n", 1.0 * ans / 2);
    return 0;
}