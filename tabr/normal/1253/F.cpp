#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct edge {
    int from;
    int to;
    long long cost;
    edge() {}
    edge(int _from, int _to, ll _cost) : from(_from), to(_to), cost(_cost) {}
};

bool operator<(edge i, edge j) {
    return i.cost < j.cost;
}

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<edge> edges(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        edges[i] = {x, y, w};
        g[x].emplace_back(i);
        g[y].emplace_back(i);
    }
    vector<int> a(q), b(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<ll> d(n, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < k; i++) {
        d[i] = 0;
        pq.emplace(0, i);
    }
    while (!pq.empty()) {
        int v;
        ll cost;
        tie(cost, v) = pq.top();
        pq.pop();
        if (d[v] != cost) {
            continue;
        }
        for (int id : g[v]) {
            int to = v ^ edges[id].from ^ edges[id].to;
            if (d[to] > d[v] + edges[id].cost) {
                d[to] = cost + edges[id].cost;
                pq.emplace(d[to], to);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        edges[i].cost += d[edges[i].from] + d[edges[i].to];
    }
    sort(edges.begin(), edges.end());
    vector<ll> lo(q), hi(q, 1e14);
    while (true) {
        vector<pair<ll, int>> que(q);
        for (int i = 0; i < q; i++) {
            if (hi[i] - lo[i] > 1) {
                que[i] = make_pair((hi[i] + lo[i]) / 2, i);
            } else {
                que[i].first = 1e18;
            }
        }
        sort(que.begin(), que.end());
        if (que[0].first == 1e18) {
            break;
        }
        int cur = 0;
        dsu uf(n);
        for (int i = 0; i < q; i++) {
            if (que[i].first == 1e18) {
                break;
            }
            while (cur != m && edges[cur].cost <= que[i].first) {
                uf.unite(edges[cur].from, edges[cur].to);
                cur++;
            }
            int j = que[i].second;
            if (uf.same(a[j], b[j])) {
                hi[j] = que[i].first;
            } else {
                lo[j] = que[i].first;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << hi[i] << '\n';
    }
    return 0;
}