#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n), mxdep(n), son(n, -1);
    function<void(int,int)> dfs = [&](int u, int fa) {
        mxdep[u] = dep[u];
        for(int v : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            if(son[u] == -1 || mxdep[son[u]] < mxdep[v]) {
                son[u] = v;
            }
            mxdep[u] = max(mxdep[u], mxdep[v]);
        }
    };
    dfs(0, -1);
    vector<int> a;
    function<void(int,int,int)> dfs2 = [&](int u, int fa, int cnt) {
        if(son[u] != -1) {
            dfs2(son[u], u, cnt + 1);
        } else {
            a.push_back(cnt);
        }
        for(int v : g[u]) {
            if(v == fa || v == son[u]) continue;
            dfs2(v, u, 1);
        }
    };
    dfs2(0, -1, 1);
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0; ll ans = -1e18;
    for(int i = 0; i < k; ++i) {
        if(i < a.size()) sum += a[i];
        int r = i + 1, x = n - sum;
        // 0 <= b <= x, w = n - r - b
        // min (n - r - b) * (r - b)
        // b^2 - nb + nr - r^2
        x = min(x, n / 2);
        ans = max(ans, 1ll * x * x - 1ll * n * x + 1ll * n * r - 1ll * r * r);
    }
    cout << ans << '\n';
}