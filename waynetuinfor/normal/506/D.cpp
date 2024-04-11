#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, k = 320;
vector<pair<int, int>> edge[maxn];
vector<pair<int, int>> query;
int cnt[maxn];

struct DisjointSet {
    int p[maxn], sz[maxn], n;
    vector<pair<int*, int>> h;
    vector<int> sp;
    void init(int size) {
        n = size;
        for (int i = 0; i < n; ++i) p[i] = i, sz[i] = 1;
        sp.clear(); h.clear();
    }
    void assign(int *k, int v) {
        h.push_back(make_pair(k, *k));
        *k = v;
    }
    void save() {
        sp.push_back(h.size());
    }
    void undo() {
        assert(sp.size());
        int last = sp.back(); sp.pop_back();
        while (h.size() != last) {
            pair<int*, int> pi = h.back(); h.pop_back();
            *pi.first = pi.second;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        assign(&sz[x], sz[x] + sz[y]);
        assign(&p[y], x);
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        edge[c].push_back(minmax(a, b));
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        query.push_back(minmax(a, b));
    }
    dsu.init(maxn);
    vector<pair<int, int>> add;
    for (int i = 1; i <= m; ++i) if (edge[i].size()) {
        vector<int> vertex;
        for (auto e : edge[i]) dsu.merge(e.first, e.second), vertex.push_back(e.first), vertex.push_back(e.second);
        if (edge[i].size() > k) {
            for (int j = 0; j < q; ++j) if (dsu.find(query[j].first) == dsu.find(query[j].second)) ++cnt[j];            
            for (auto e : edge[i]) dsu.p[e.first] = e.first, dsu.p[e.second] = e.second;
            continue;
        } 
        sort(vertex.begin(), vertex.end()); vertex.resize(unique(vertex.begin(), vertex.end()) - vertex.begin());
        for (size_t j = 0; j < vertex.size(); ++j) {
            for (size_t k = j + 1; k < vertex.size(); ++k) {
                if (dsu.find(vertex[j]) == dsu.find(vertex[k])) add.push_back(minmax(vertex[j], vertex[k]));
            }
        }
        for (auto e : edge[i]) dsu.p[e.first] = e.first, dsu.p[e.second] = e.second;
    }
    sort(add.begin(), add.end());
    for (int i = 0; i < q; ++i) {
        auto ub = upper_bound(add.begin(), add.end(), query[i]), lb = lower_bound(add.begin(), add.end(), query[i]);
        cout << cnt[i] + ub - lb << endl;
    }
    return 0;
}