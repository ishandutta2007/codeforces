#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const long long oo = (long long)1e18 + 7;

typedef long long ll;

struct DSU {
    vector<int> pset;

    DSU(int n) {
        pset.resize(n);
        for(int i = 0; i < n; ++i)
            pset[i] = i;
    }

    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }

    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q)
            return false;
        pset[p] = q;
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int n, m, k, q, root[MAXN];
long long dist[MAXN];
vector<int> graph[MAXN];
vector<Edge> edges, eCentral;

int a[MAXN], b[MAXN], lo[MAXN], hi[MAXN], res[MAXN];
vector<int> qInd[MAXN];

void dijkstra() {
    fill(dist, dist+n, oo);
    fill(root, root+n, -1);
    vector<bool> avail(n, true);
    set<pair<ll, int>> s;

    for(int u = 0; u < k; ++u) {
        dist[u] = 0;
        root[u] = u;
        s.insert({dist[u], u});
    }

    while (!s.empty()) {
        int u = s.begin()->second; s.erase(s.begin());
        if (!avail[u])
            continue;
        avail[u] = false;

        for(int i: graph[u]) {
            int v = edges[i].u + edges[i].v - u, w = edges[i].w;
            if (avail[v] && dist[v] > dist[u] + w) {
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                root[v] = root[u];
                s.insert({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u; --v;

        edges.push_back({u, v, w});
        graph[u].push_back(i);
        graph[v].push_back(i);
    }
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        --a[i]; --b[i];
    }

    dijkstra();

//    for(int u = 0; u < n; ++u)
//        printf("%d %lld\n", root[u], dist[u]);

    for(Edge e: edges) {
        int p = root[e.u], q = root[e.v];
        if (p != q)
            eCentral.push_back({p, q, dist[e.u] + dist[e.v] + e.w});
    }
    sort(eCentral.begin(), eCentral.end(), [](Edge &a, Edge &b) {
        return a.w < b.w;
    });

//    for(Edge e: eCentral) {
//        printf("%d %d %lld\n", e.u, e.v, e.w);
//    }

    for(int i = 0; i < q; ++i) {
        lo[i] = 0;
        hi[i] = eCentral.size() - 1;
        res[i] = -1;
    }

    while (true) {
        bool stop = true;
        for(int i = 0; i < q; ++i) {
            if (lo[i] <= hi[i]) {
                int mid = (lo[i] + hi[i]) / 2;
                qInd[mid].push_back(i);
                stop = false;
            }
        }
        if (stop)
            break;

        DSU s(k);

        for(int x = 0; x < eCentral.size(); ++x) {
            s.unionSet(eCentral[x].u, eCentral[x].v);
            for(int id: qInd[x]) {
                int mid = (lo[id] + hi[id]) / 2;
//                printf("%d\n", mid);
//                for(int u = 0; u < k; ++u)
//                    printf("%d ", s.findSet(u));
//                puts("");
                if (s.findSet(a[id]) == s.findSet(b[id])) {
                    res[id] = mid;
                    hi[id] = mid - 1;
                } else
                    lo[id] = mid + 1;
            }
            qInd[x].clear();
        }
    }

    for(int i = 0; i < q; ++i) {
        long long ans = eCentral[res[i]].w;
        printf("%lld\n", ans);
    }

    return 0;
}