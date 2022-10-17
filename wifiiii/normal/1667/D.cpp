#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        map<pair<int,int>, int> mp;
        vector<pair<int,int>> es(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if(u > v) swap(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
            es[i] = {u, v};
            mp[{u, v}] = i;
        }
        auto chk = [&](vector<int> &cnt) -> int {
            if(cnt[0]) return 0;
            if(cnt[2] >= cnt[1]) {
                return cnt[2] - (cnt[1] + 1) <= cnt[3];
            }
            return cnt[1] - cnt[2] <= cnt[3];
        };
        vector<int> dp(n);
        int ok = 1;
        function<void(int, int)> dfs = [&](int u, int fa) {
            vector<int> cnt(4);
            for(int v : g[u]) {
                if(v == fa) continue;
                dfs(v, u);
                cnt[dp[v]] += 1;
            }
            if(fa == -1) {
                dp[u] = chk(cnt);
                return;
            }
            int x = 0;
            cnt[1]++; if(chk(cnt)) x |= 1; cnt[1]--;
            cnt[2]++; if(chk(cnt)) x |= 2; cnt[2]--;
            dp[u] = x;
        };
        dfs(0, -1);
        if(dp[0]) {
            cout << "YES\n";
            vector<pair<int,int>> ans;
            vector<int> val(n);
            vector<vector<int>> G(n); vector<int> deg(n);
            function<void(int, int)> dfs2 = [&](int u, int fa) {
                vector<int> cnt(4);
                vector<vector<int>> b(4);
                for(int v : g[u]) {
                    if(v == fa) continue;
                    cnt[dp[v]] += 1;
                    b[dp[v]].push_back(v);
                }
                int p = 2;
                if(fa != -1) {
                    ++cnt[val[u]];
                    b[val[u]].push_back(fa);
                }
                vector<int> c;
                while(cnt[1] || cnt[2] || cnt[3]) {
                    assert(cnt[p] || cnt[3]);
                    int v = -1;
                    if(cnt[p]) {
                        --cnt[p]; v = b[p].back(); b[p].pop_back();
                    } else {
                        --cnt[3]; v = b[3].back(); b[3].pop_back();
                    }
                    auto [l, r] = minmax({u, v});
                    c.push_back(mp[{l, r}]);
                    val[v] = p;
                    p = 3 - p;
                }
                reverse(c.begin(), c.end());
                for(int i = 1; i < c.size(); ++i) {
                    G[c[i - 1]].push_back(c[i]);
                    ++deg[c[i]];
                }
                for(int v : g[u]) {
                    if(v == fa) continue;
                    dfs2(v, u);
                }
            };
            dfs2(0, -1);
            queue<int> q;
            for(int i = 1; i < n; ++i) if(!deg[i]) q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                cout << es[u].first + 1 << ' ' << es[u].second + 1 << '\n';
                for(int v : G[u]) {
                    if(--deg[v] == 0) {
                        q.push(v);
                    }
                }
            }
        } else {
            cout << "NO\n";
        }
    }
}