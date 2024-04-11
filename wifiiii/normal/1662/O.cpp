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
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        ufind uf(21 * 360);
        vector<vector<pair<int,int>>> cs(21);
        vector<vector<int>> s(21, vector<int>(360));
        for(int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if(c == 'C') {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                cs[r].push_back({t1, t2});
            } else {
                int r1, r2, t;
                cin >> r1 >> r2 >> t;
                for(int j = r1; j < r2; ++j) {
                    s[j][t] = 1;
                }
            }
        }
        for(int i = 0; i <= 20; ++i) {
            vector<int> c(360);
            for(auto [l, r] : cs[i]) {
                if(l < r) {
                    for(int j = l; j < r; ++j) {
                        c[j] = 1;
                    }
                } else {
                    for(int j = l; j < 360; ++j) {
                        c[j] = 1;
                    }
                    for(int j = 0; j < r; ++j) {
                        c[j] = 1;
                    }
                }
            }
            for(int j = 0; j < 360; ++j) {
                if(i > 0 && !c[j]) uf.merge(i * 360 + j, (i - 1) * 360 + j);
            }
            for(int j = 0; j < 360; ++j) {
                if(!s[i][j]) {
                    uf.merge(i * 360 + j, i * 360 + (j + 359) % 360);
                }
            }
        }
        int ok = 0;
        for(int i = 0; i < 360; ++i) {
            if(uf.find(20 * 360 + i) == uf.find(0)) ok = 1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}