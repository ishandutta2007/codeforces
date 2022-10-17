#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = g[v][u] = 1;
    }
    map<vector<int>, int> vis;
    {
        vector<int> mch(n, -1);
        function<void(int)> dfs = [&](int p) {
            if(p == n) {
                // check mch
                vector<pair<int,int>> ps;
                for(int i = 0; i < n; ++i) {
                    if(i < mch[i]) ps.push_back({i, mch[i]});
                }
                sort(ps.begin(), ps.end());
                do {
                    int ok = 1;
                    for(int i = 1; i < n / 2; ++i) {
                        auto [u1, v1] = ps[i];
                        auto [u2, v2] = ps[i-1];
                        if(!((g[u1][u2]&&g[v1][v2])||(g[u1][v2]&&g[u2][v1]))) {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok && !g[ps[n/2-1].first][ps[n/2-1].second]) ok=0;
                    if(ok) {
                        vis[mch]=1;
                        break;
                    }
                } while(next_permutation(ps.begin(), ps.end()));
                return;
            }
            if(mch[p] != -1) {
                dfs(p + 1);
                return;
            }
            for(int i = p + 1; i < n; ++i) {
                if(mch[i] == -1) {
                    mch[i] = p; mch[p] = i;
                    dfs(p + 1);
                    mch[i] = mch[p] = -1;
                }
            }
        };
        dfs(0);
    }
    ll ans = 0;
    vector<int> c(n), cnt(n);
    vector<ll> num(n + 1);
    num[0] = k;
    for(int i = 1; i <= n; ++i) num[i] = num[i-1] * (k - i);
    function<void(int,int)> dfs = [&](int p, int mx) {
        if(p == n) {
            for(int i = 0; i <= mx; ++i) if(cnt[i] & 1) return;
            vector<int> mch(n, -1);
            function<int(int)> dfs2 = [&](int p) {
                if(p == n) {
                    if(vis.count(mch)) {
                        ans += num[mx];
                        return 1;
                    }
                    return 0;
                }
                if(mch[p] != -1) return dfs2(p + 1);
                for(int i = p + 1; i < n; ++i) {
                    if(mch[i] == -1 && c[i] == c[p]) {
                        mch[i] = p; mch[p] = i;
                        if(dfs2(p + 1)) return 1;
                        mch[i] = mch[p] = -1;
                    }
                }
                return 0;
            };
            dfs2(0);
            return;
        }
        for(int i = 0; i <= mx+1; ++i) {
            c[p] = i;
            cnt[i]++;
            dfs(p + 1, max(i, mx));
            cnt[i]--;
        }
    };
    dfs(0, -1);
    cout << ans << '\n';
}