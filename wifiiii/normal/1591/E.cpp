#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
    int kth(T x) { // min pos s.t. [0, pos] >= x
        assert(x >= 0);
        int lg = 31 - __builtin_clz(n), pos = 0;
        for(int i = 1 << lg; i; i >>= 1) {
            if(pos + i <= n && a[pos + i - 1] < x) {
                pos += i;
                x -= a[pos - 1];
            }
        }
        return pos;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<vector<int>> g(n);
        vector<vector<tuple<int,int,int>>> qs(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        for(int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            g[p].push_back(i);
        }
        vector<int> ans(q);
        for(int i = 0; i < q; ++i) {
            int u, l, k;
            cin >> u >> l >> k;
            --u;
            qs[u].push_back({l, k, i});
        }
        vector<int> occ(n);
        fenwick<int> fen(n + 1);
        vector<unordered_set<int>> s(n + 1);
        function<void(int)> dfs = [&](int u) {
            if(occ[a[u]]) fen.add(occ[a[u]], -1), s[occ[a[u]]].erase(a[u]);
            occ[a[u]] += 1, s[occ[a[u]]].insert(a[u]);
            fen.add(occ[a[u]], 1);
            for(auto [l, k, id] : qs[u]) {
                int s1 = fen.qry(l - 1), s2 = fen.qry(n);
                if(s1 + k > s2) {
                    ans[id] = -2;
                    continue;
                }
                ans[id] = *s[fen.kth(s1 + k)].begin();
            }
            for(int v : g[u]) {
                dfs(v);
            }
            fen.add(occ[a[u]], -1), s[occ[a[u]]].erase(a[u]);
            occ[a[u]] -= 1;
            if(occ[a[u]]) fen.add(occ[a[u]], 1), s[occ[a[u]]].insert(a[u]);
        };
        dfs(0);

        for(int i = 0; i < q; ++i) cout << ans[i] + 1 << " "; cout << '\n';
    }
}