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
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<double,int,int,int>> es1, es2;
    int deg = 0;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        if(!u || !v) {
            es1.push_back({w, u, v, i});
        } else {
            es2.push_back({w, u, v, i});
        }
    }
    sort(es1.begin(), es1.end());
    sort(es2.begin(), es2.end());
    double lo = -1e9, hi = 1e9;
    for(int i = 0; i < 60; ++i) {
        double mid = (lo + hi) / 2;
        ufind uf(n);
        int cnt = 0;
        for(auto &[w, u, v, ind] : es1) w += mid;
        vector<tuple<double,int,int,int>> es;
        merge(es1.begin(), es1.end(), es2.begin(), es2.end(), back_inserter(es));
        for(auto [w, u, v, ind] : es) {
            if(uf.merge(u, v)) {
                if(!u || !v) ++cnt;
            }
        }
        for(auto &[w, u, v, ind] : es1) w -= mid;
        if(cnt < k) hi = mid;
        else lo = mid;
    }
    ufind uf(n);
    for(auto &[w, u, v, ind] : es1) w += lo;
    vector<tuple<double,int,int,int>> es;
    merge(es1.begin(), es1.end(), es2.begin(), es2.end(), back_inserter(es));
    int cnt = 0;
    vector<int> s;
    for(auto [w, u, v, ind] : es) {
        if(cnt == k && (!u || !v)) continue;
        if(uf.merge(u, v)) {
            if(!u || !v) ++cnt;
            s.push_back(ind);
        }
    }
    if(cnt != k || s.size() != n - 1) {
        cout << -1 << '\n';
    } else {
        cout << s.size() << '\n';
        for(int i : s) cout << i + 1 << " "; cout << '\n';
    }
}