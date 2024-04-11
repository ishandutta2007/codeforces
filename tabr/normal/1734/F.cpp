#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

map<tuple<long long, long long, int>, long long> memo;

long long Solve(long long n, long long m, int k) {
    if (memo.count(make_tuple(n, m, k))) {
        return memo[make_tuple(n, m, k)];
    }
    long long res = 0;
    long long t = 1LL << (k - 1);
    assert(n + m <= t * 2);
    if (m <= t) {
        if (n + m <= t) {
            res = Solve(n, m, k - 1);
        } else if (n >= t) {
            res = m - Solve(n - t, m, k - 1);
        } else {
            res = Solve(n, t - n, k - 1) + (m - t + n) - Solve(t - n, m - t + n, k - 1);
        }
    } else {
        res = Solve(n, t - n, k - 1) + Solve(n, m - t, k - 1) + n - Solve(t - n, n, k - 1);
    }
    return memo[make_tuple(n, m, k)] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s = "01101001";
    for (int n = 0; n <= 2; n++) {
        for (int m = 0; m <= 2; m++) {
            int t = 0;
            for (int i = 0; i < m; i++) {
                t += (s[i] != s[i + n]);
            }
            memo[make_tuple(n, m, 1)] = t;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, m;
        cin >> n >> m;
        cout << Solve(n, m, 61) << '\n';
    }
    return 0;
}