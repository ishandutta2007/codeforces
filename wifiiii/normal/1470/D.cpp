#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}

// usage :
// auto gcd = y_combinator([&](auto gcd, int a, int b) -> int {
//         return b == 0 ? a : gcd(b, a % b);
// });
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> vis(n), dep(n), ins(n), ans;
        auto dfs = y_combinator([&](auto dfs, int u) -> void {
            int ok = 1;
            for(int v : g[u]) {
                if(ins[v]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                ans.push_back(u);
                ins[u] = 1;
            }
            vis[u] = 1;
            for(int v : g[u]) {
                if(vis[v]) continue;
//                dep[v] = dep[u] ^ 1;
                dfs(v);
            }
        });
        dfs(0);
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for(int i : ans) cout << i + 1 << " "; cout << '\n';
    }
}