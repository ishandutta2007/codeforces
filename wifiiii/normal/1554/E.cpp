#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> dp(n);
        int ok = 1, x = 0;
        function<void(int,int,int)> dfs = [&](int u, int fa, int k) {
            dp[u] = 1;
            int sum = 0;
            for(int v : g[u]) {
                if(v == fa) continue;
                dfs(v, u, k);
                sum += dp[v];
            }
            if(sum % k == 0) {
                x = gcd(x, sum);
            } else if (fa != -1 && (sum + 1) % k == 0) {
                x = gcd(x, sum + 1);
                dp[u] = 0;
            } else {
                ok = 0;
            }
        };
        vector<int> ans(n + 1);
        ll tot = 1;
        for(int i = 1; i < n; ++i) tot = tot * 2 % mod;
        for(int i = 2; i <= n; ++i) {
            if((n - 1) % i == 0) {
                x = 0; ok = 1;
                dfs(0, -1, i);
                if(ok && x == i) {
                    ans[i] = 1;
                    --tot;
                }
            }
        }
        tot = (tot + mod) % mod;
        ans[1] = tot;
        for(int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl;
    }
}