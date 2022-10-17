#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n), szb(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        szb[u] = a[u], sz[u] = 1;
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            szb[u] += szb[v];
            sz[u] += sz[v];
        }
    };
    dfs(0, -1);

    vector<int> c(n);
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int v : g[i]) {
            if(sz[v] > sz[i]) {
                if(szb[i] != szb[0]) {
                    cnt += 1;
                }
            } else {
                if(szb[v]) {
                    cnt += 1;
                }
            }
        }
        c[i] = cnt;
    }
    int qwq = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i]) {
            for(int v : g[i]) {
                if(a[v]) {
                    qwq = 1;
                }
                if(c[v] > 2) {
                    qwq = 1;
                }
            }
            if(c[i] > 1) {
                qwq = 1;
            }
        }
        int cnt = 0;
        for(int v : g[i]) {
            cnt += a[v];
        }
        if(cnt > 1) qwq = 1;
    }
    if(qwq) {
        for(int i = 0; i < n; ++i) {
            cout << 1 << " ";
        }
        cout << '\n';
        return 0;
    }
    vector<int> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i]) {
            ans[i] = 1;
            for(int v : g[i]) {
                ans[v] = 1;
            }
        }
    }

    function<int(int)> dfs2 = [&](int u) -> int {
        if(ans[u] != -1) return ans[u];
        int cnt = 0, p = -1;
        for(int v : g[u]) {
            if(sz[v] > sz[u]) {
                if(szb[u] != szb[0]) {
                    cnt += 1;
                    p = v;
                }
            } else {
                if(szb[v]) {
                    cnt += 1;
                    p = v;
                }
            }
        }
        if(cnt > 1) {
            return ans[u] = 0;
        }
        assert(p != -1);
        return ans[u] = dfs2(p);
    };
    for(int i = 0; i < n; ++i) cout << dfs2(i) << ' ';
    cout << '\n';
}