#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> sieve(int n) {
    vector<int> lp(n + 1), pr;
    for (int x = 2; x <= n; ++x) {
        if (lp[x] == 0) pr.push_back(lp[x] = x);
        for (auto p : pr) {
            if (p > lp[x] || p * x > n) break;
            lp[p * x] = p;
        }
    }
    return lp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int amax = 1e7, kmax = 20;
    auto lp = sieve(amax);
    auto f = [&](int x) {
        int y = 1;
        for (int p = lp[x]; x != 1; p = lp[x]) {
            int e = 0;
            while (x % p == 0) x /= p, e ^= 1;
            if (e) y *= p;
        }
        return y;
    };
    vector<int> last(amax + 1, -1);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<array<int, kmax + 1>> dp(n);
        deque<int> pos;
        for (int i = 0; i < n; ++i) {
            int &x = a[i];
            cin >> x;
            x = f(x);
            if (last[x] != -1) {
                pos.push_back(last[x]);
                inplace_merge(begin(pos), end(pos) - 1, end(pos));
            }
            last[x] = i;
            if (empty(pos)) {
                fill(begin(dp[i]), end(dp[i]), 1);
            }
            else {
                fill(begin(dp[i]), end(dp[i]), n);
                if ((int)size(pos) == k + 2) pos.pop_front();
                int m = (int)size(pos);
                for (int l = m - 1; l >= 0; --l) {
                    int z = m - 1 - l;
                    for (int j = 0; j + z <= k; ++j) {
                        dp[i][j + z] = min(dp[i][j + z], 1 + dp[pos[l]][j]);
                    }
                }
                if (m <= k) dp[i][m] = 1;
            }
            partial_sum(begin(dp[i]), end(dp[i]), begin(dp[i]), [&](int x, int y){ return min(x, y); });
        }
        for (int i = 0; i < n; ++i) last[a[i]] = -1;
        cout << dp[n - 1][k] << endl;
    }
    exit(0);
}