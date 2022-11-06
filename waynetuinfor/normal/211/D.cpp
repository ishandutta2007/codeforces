#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], l[maxn], r[maxn];
long long slp[maxn], cst[maxn];
long long sum[maxn];

long long solve(int k, int n) {
    long long res = 0;
    for (int i = 0; i + k <= n; ++i) {
        int add = 1e9;
        for (int j = 0; j < k; ++j) add = min(add, a[i + j]);
        res += add;
    }
    return res;
}

void AddSlope(int l, int r, long long v) {
    slp[l] += v;
    slp[r + 1] -= v;
}

void AddConst(int l, int r, long long v) {
    cst[l] += v;
    cst[r + 1] -= v;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        l[i] = i - 1;
        while (l[i] >= 0 && a[l[i]] > a[i])
            l[i] = l[l[i]];
    }
    for (int i = n - 1; i >= 0; --i) {
        r[i] = i + 1;
        while (r[i] < n && a[r[i]] >= a[i])
            r[i] = r[r[i]];
    }

    for (int i = 0; i <= n; ++i) sum[i] = 0;

    for (int i = 0; i < n; ++i) {
        int lt = i - l[i] - 1, rg = r[i] - i - 1;
        int x = min(lt, rg) + 1, y = max(lt, rg) + 1, t = lt + rg + 1;
        AddSlope(y + 1, lt + rg + 1, -a[i]);
        AddConst(y + 1, lt + rg + 1, 1LL * (t + 1) * a[i]);
        AddConst(x, y, 1LL * (t - y + 1) * a[i]);
        AddSlope(1, x - 1, a[i]);
    }

    long long s = 0, c = 0;

    for (int i = 0; i <= n; ++i) {
        s += slp[i];
        c += cst[i];
        sum[i] = s * i + c;
    }

    int q; scanf("%d", &q);
    while (q--) {
        int k; scanf("%d", &k);
        double ans = 1.0 * sum[k] / (n - k + 1);
        printf("%.20lf\n", ans);
    }

    return 0;
}