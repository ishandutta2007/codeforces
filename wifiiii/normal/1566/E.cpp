#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        int ans = 0, f = 0;
        function<int(int,int)> dfs = [&](int u, int fa) -> int {
            if(u != 0 && g[u].size() == 1) return 1;
            int cnt = 0;
            for(int v : g[u]) {
                if(v == fa) continue;
                int tmp = dfs(v, u);
                cnt += tmp;
                if(u == 0 && tmp == 1) ++ans, f = 1;
            }
            if(u != 0 && cnt >= 1) ans += cnt - 1;
            return cnt == 0;
        };
        dfs(0, -1);
        ans += 1 - f;
        cout << ans << '\n';
    }
}