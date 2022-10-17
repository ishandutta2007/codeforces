#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ufind {
    vector<int> par, sz, w;
    ufind(int n) : par(n), sz(n, 1), w(n) {
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
        w[x] = min(w[x], w[y]);
        par[y] = x;
        return 1;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int, vector<pair<int,int>>> mx, my;
        ufind uf(n);
        for(int i = 0; i < n; ++i) {
            int x, y, w;
            cin >> x >> y >> w;
            uf.w[i] = w;
            mx[x].push_back({y, i});
            my[y].push_back({x, i});
        }
        for(auto &[x, v] : mx) {
            sort(v.begin(), v.end());
            int li = -1, lp = -1;
            for(auto [y, i] : v) {
                if(li != -1 && y - lp <= k) {
                    uf.merge(i, li);
                }
                li = i, lp = y;
            }
        }
        for(auto &[y, v] : my) {
            sort(v.begin(), v.end());
            int li = -1, lp = -1;
            for(auto [x, i] : v) {
                if(li != -1 && x - lp <= k) {
                    uf.merge(i, li);
                }
                li = i, lp = x;
            }
        }
        vector<int> a;
        for(int i = 0; i < n; ++i) {
            if(uf.find(i) == i) {
                a.push_back(uf.w[i]);
            }
        }
        sort(a.begin(), a.end());
        if(a.size() <= 1) {
            cout << 0 << '\n';
        } else {
            int ans = a.size() - 1;
            for(int i = a.size() - 2; i >= 0; --i) {
                ans = min(ans, max(a[i], (int)a.size() - 2 - i));
            }
            cout << ans << '\n';
        }
    }
}