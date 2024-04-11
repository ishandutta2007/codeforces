#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<pair<int,int>> a(q);
    for(auto &[x, y] : a) cin >> x >> y;
    auto solve = [&]() -> int {
        set<pair<int,int>> vis;
        for(auto [x, y] : a) {
            vis.insert({x, y});
        }
        vector<int> dp(n + 1, -1); dp[1] = 1;
        for(int i = 1; i <= 30; ++i) {
            vector<int> ndp(n + 1, -1);
            for(int j = 1; j <= n; ++j) {
                // (j, dp[j]) -> (j + dp[j], dp[j])
                //            -> (j, j + dp[j])
                if(dp[j] != -1) {
                    int p = j + dp[j] + vis.count({j, dp[j]});
                    ndp[min(p, n)] = max(ndp[min(p, n)], dp[j]);
                    ndp[j] = max(ndp[j], min(p, m));
                }
            }
            dp = ndp;
            if(dp[n] != -1) {
                int ret = i, cur = dp[n];
                while(cur < m) {
                    cur = n + cur + vis.count({n, cur});
                    ret += 1;
                }
                return ret;
            }
        }
        return 1e9;
    };
    int ans = solve();
    swap(n, m);
    for(auto &[x, y] : a) swap(x, y);
    ans = min(ans, solve());
    cout << ans << '\n';
}