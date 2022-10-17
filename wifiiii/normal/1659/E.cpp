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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    vector<ufind> uf(30, ufind(n));
    vector<ufind> uf2(30, ufind(n + 1));
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        for(int j = 29; j >= 0; --j) {
            if(w >> j & 1) {
                uf[j].merge(u, v);
            }
        }
        for(int j = 29; j >= 1; --j) {
            if(w >> j & 1) {
                uf2[j].merge(u, v);
            }
        }
        if(w % 2 == 0) {
            // u, v
            for(int j = 29; j >= 1; --j) {
                uf2[j].merge(u, n);
                uf2[j].merge(v, n);
            }
        }
    }
    auto solve = [&](int u, int v) {
        for(int i = 0; i < 30; ++i) {
            if(uf[i].same(u, v)) return 0;
        }
        for(int i = 0; i < 30; ++i) {
            if(uf2[i].same(u, n)) return 1;
        }
        return 2;
    };

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << solve(u, v) << '\n';
    }
}