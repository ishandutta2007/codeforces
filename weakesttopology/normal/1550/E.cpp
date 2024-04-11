#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c == '?' ? -1 : c - 'a';
    }
    vector<vector<int>> nxt(k, vector<int>(n + 1, n));
    auto check = [&](int L) {
        for (int c = 0; c < k; ++c) {
            for (int i = n - 1, last = n; i >= 0; --i) {
                if (a[i] != c && a[i] != -1) last = i;
                nxt[c][i] = last >= i + L ? i : nxt[c][i + 1];
            }
        }
        vector<int> dp(1 << k, n + 1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (dp[mask] == n + 1) continue;
            for (int c = 0; c < k; ++c) {
                int i = nxt[c][dp[mask]];
                if (i < n) chmin(dp[mask | 1 << c], i + L);
            }
        }
        return dp.back() <= n;
    };
    int L = 0, R = n + 1;
    while (L + 1 < R) {
        int M = L + (R - L) / 2;
        check(M) ? L = M : R = M;
    }
    cout << L << '\n';
    exit(0);
}