#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int dp[4000004];
int suf[4000004];
int spf[4000004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    function<vector<pair<int, int>>(int)> factor = [&](int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = spf[n];
            res.emplace_back(p, 0);
            while (p == spf[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    };
    function<vector<int>(int)> divisor = [&](int n) {
        vector<int> res(1, 1);
        vector<pair<int, int>> f = factor(n);
        for (auto p : f) {
            for (int i = (int) res.size() - 1; i >= 0; i--) {
                int c = res[i];
                for (int j = 0; j < p.second; j++) {
                    c *= p.first;
                    res.emplace_back(c);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    };
    int n, mod;
    cin >> n >> mod;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (spf[j] == 0) {
                spf[j] = i;
            }
        }
    }
    dp[n] = 1;
    for (int i = n; i >= 1; i--) {
        dp[i] += suf[i + 1];
        if (dp[i] >= mod) {
            dp[i] -= mod;
        }
        suf[i] = dp[i] + suf[i + 1];
        if (suf[i] >= mod) {
            suf[i] -= mod;
        }
        for (int j : divisor(i)) {
            if (j == 1) {
                continue;
            }
            int k = i / j;
            dp[k] += suf[i];
            if (dp[k] >= mod) {
                dp[k] -= mod;
            }
            if (i + j <= n) {
                dp[k] += mod - suf[i + j];
                if (dp[k] >= mod) {
                    dp[k] -= mod;
                }
            }
        }
    }
    cout << dp[1] << '\n';
    return 0;
}