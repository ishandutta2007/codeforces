#ifndef tabr
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    vector<int> mp(n + 1);
    vector<int> tmp(n + 1);
    for (int i = 2; i <= n; i++) {
        if (tmp[i]) {
            continue;
        }
        for (long long x = i; x <= n; x *= i) {
            mp[i]++;
            tmp[x] = 1;
        }
    }
    vector<int> c(30, -1);
    c[0] = 0;
    c[1] = m;
    auto f = [&](int x) {
        if (c[x] != -1) {
            return c[x];
        }
        vector<int> b(x * m + 1);
        for (int i = 1; i <= x; i++) {
            int t = 0;
            for (int j = 1; j <= m; j++) {
                t += i;
                b[t] = 1;
            }
        }
        c[x] = accumulate(b.begin(), b.end(), 0);
        return c[x];
    };
    for (int i = 2; i <= n; i++) {
        ans += f(mp[i]);
    }
    cout << ans << '\n';
    return 0;
}