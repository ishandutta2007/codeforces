#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T, typename F = function<T(const T &, const T &)>>
struct stable {
    int n;
    vector<vector<T>> st;
    F f;
    stable(const vector<T> &a, const F &f) : f(f), n(a.size()) {
        assert(n);
        int lg = 32 - __builtin_clz(n);
        st.resize(lg);
        st[0] = a;
        for(int i = 1; i < lg; ++i) {
            st[i].resize(n + 1 - (1 << i));
            for(int j = 0; j < n + 1 - (1 << i); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T qry(int l, int r) {
        // 0 <= l <= r < n
        int k = 31 - __builtin_clz(r - l + 1);
        return f(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

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
        vector<int> dep(n), f(n, -1), sz(n), mxdep(n);
        function<void(int,int)> dfs = [&](int u, int fa) {
            sz[u] = 1;
            mxdep[u] = dep[u];
            for(int v : g[u]) {
                if(v == fa) continue;
                dep[v] = dep[u] + 1;
                f[v] = u;
                dfs(v, u);
                mxdep[u] = max(mxdep[u], mxdep[v]);
                sz[u] += sz[v];
            }
        };
        dfs(0, -1);
        int p = max_element(dep.begin(), dep.end()) - dep.begin(), mx = dep[p];
        vector<int> a {p};
        while(p) {
            p = f[p];
            a.push_back(p);
        }
        reverse(a.begin(), a.end());
        vector<int> b(a.size()), c(a.size()), pmx(a.size());
        for(int i = 0; i < a.size(); ++i) {
            int x = i + 1 < a.size() ? a[i + 1] : -1;
            b[i] = dep[a[i]];
            for(int u : g[a[i]]) {
                if(u == x || u == f[a[i]]) continue;
                b[i] = max(b[i], mxdep[u]);
            }
            c[i] = b[i] - 2 * i;
            pmx[i] = i ? max(pmx[i - 1], b[i]) : b[i];
        }
        stable st(c, [&](int i, int j) {return max(i, j);});
        for(int x = 1; x <= n; ++x) {
            if(x >= mx) {
                cout << mx << ' ';
                continue;
            }
            int lo = x, hi = mx;
            while(lo < hi) {
                int mid = (lo + hi) / 2;
                int d = a.size() - 1 - mid;
                if(st.qry(x + d - d / 2, x + d) + 2 * (x + d) <= mid + d && pmx[x + d - d / 2 - 1] <= mid) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << lo << ' ';
        }
        cout << '\n';
    }
}