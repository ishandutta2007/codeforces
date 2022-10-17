#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ufind {
    vector<int> par, sz;
    ufind(int n) : par(n), sz(n, 1) {
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if(x != par[x]) return par[x] = find(par[x]);
        return x;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int same(int u, int v) {
        return find(u) == find(v);
    }
    int merge(int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return 0;
        if(sz[x] < sz[y]) swap(sz[x], sz[y]), swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int,int,int>> es(m);
        for(auto &[u, v, w] : es) {
            cin >> u >> v >> w;
            --u, --v;
        }
        int ans = 0;
        for(int i = 29; i >= 0; --i) {
            ufind uf(n);
            for(auto [u, v, w] : es) {
                if(!(w >> i & 1)) {
                    uf.merge(u, v);
                }
            }
            if(uf.size(0) != n) {
                ans |= 1 << i;
            } else {
                vector<tuple<int,int,int>> nxt;
                for(auto [u, v, w] : es) {
                    if(!(w >> i & 1)) {
                        nxt.push_back({u, v, w});
                    }
                }
                es = nxt;
            }
        }
        cout << ans << '\n';
    }
}