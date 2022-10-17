#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 1010000;
const ll inf = 1e18;

ll A, B, a[MAXN], pre[MAXN], suf[MAXN]; int n;
vector <int> pr;

void foo (int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            pr.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) pr.push_back(x);
}

int main () {
    n = read(); int i, j;
    A = read(), B = read();
    for (i = 1; i <= n; i++) a[i] = read();
    foo(a[1]), foo(a[1] - 1), foo(a[1] + 1);
    foo(a[n]), foo(a[n] - 1), foo(a[n] + 1);
    ll ans = inf;
    for (auto p: pr) {
        pre[0] = suf[n + 1] = 0;
        for (i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (a[i] % p != 0) {
                if ((a[i] - 1) % p == 0 || (a[i] + 1) % p == 0) pre[i] += B;
                else pre[i] = inf;
            }
            ans = min(ans, pre[i] + A * (n - i));
        }
        for (i = n; i >= 1; i--) {
            suf[i] = suf[i + 1];
            if (a[i] % p != 0) {
                if ((a[i] - 1) % p == 0 || (a[i] + 1) % p == 0) suf[i] += B;
                else suf[i] = inf;
            }
            ans = min(ans, suf[i] + A * (i - 1));
        }
        ll mn = inf;
        for (i = 1; i <= n; i++) {
            ans = min(ans, suf[i] + A * i - A + mn);
            mn = min(mn, pre[i] - A * i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}