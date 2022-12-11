#include <bits/stdc++.h>
using namespace std;

struct tag
{
    int s, e;
};

struct MaxFlowDinic {
    typedef int flow_t;
    struct Edge {
        int next;
        size_t inv; /* inverse edge index */
        flow_t res; /* residual */
        tag tag_;
    };
    int n;
    vector<vector<Edge>> graph;
    vector<int> q, l, start;
    void init(int _n) {
        n = _n;
        graph.resize(n);
        for (int i = 0; i < n; i++) graph[i].clear();
    }
    void add_edge(int s, int e, flow_t cap, tag tag_ = {}) {
        Edge forward{ e, graph[e].size(), cap, tag_ };
        Edge reverse{ s, graph[s].size(), 0, {} };
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }
    bool assign_level(int source, int sink) {
        int t = 0;
        memset(&l[0], 0, sizeof(l[0]) * l.size());
        l[source] = 1;
        q[t++] = source;
        for (int h = 0; h < t && !l[sink]; h++) {
            int cur = q[h];
            for (const auto& e : graph[cur]) {
                if (l[e.next] || e.res == 0) continue;
                l[e.next] = l[cur] + 1;
                q[t++] = e.next;
            }
        }
        return l[sink] != 0;
    }
    flow_t block_flow(int cur, int sink, flow_t current) {
        if (cur == sink) return current;
        for (int& i = start[cur]; i < graph[cur].size(); i++) {
            auto& e = graph[cur][i];
            if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
            if (flow_t res = block_flow(e.next, sink, min(e.res, current))) {
                e.res -= res;
                graph[e.next][e.inv].res += res;
                return res;
            }
        }
        return 0;
    }
    flow_t solve(int source, int sink) {
        q.resize(n);
        l.resize(n);
        start.resize(n);
        flow_t ans = 0;
        while (assign_level(source, sink)) {
            memset(&start[0], 0, sizeof(start[0]) * n);
            while (flow_t flow = block_flow(source, sink, numeric_limits <flow_t
                        >::max()))
                ans += flow;
        }
        return ans;
    }
};

pair<int, int> edge[5005];
int n, m;

bool check(int t, bool print = false)
{
    MaxFlowDinic mf;
    mf.init(n + m + 2);

    for (int i = 1; i <= m; i++)
    {
        mf.add_edge(0, i, 1);
        mf.add_edge(i, m + edge[i].first, 1, {edge[i].first, edge[i].second});
        mf.add_edge(i, m + edge[i].second, 1, {edge[i].second, edge[i].first});
    }

    for (int i = 1; i <= n; i++)
    {
        mf.add_edge(m + i, n + m + 1, t);
    }

    if (mf.solve(0, n + m + 1) != m) return false;

    if (print)
    {
        for (auto &vt : mf.graph) for (auto &e : vt)
        {
            if (e.res) continue;
            if (e.tag_.s == 0) continue;

            printf("%d %d\n", e.tag_.s, e.tag_.e);
        }
    }

    return true;
}

int main()
{
    scanf("%d%d",&n,&m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",&edge[i].first,&edge[i].second);
    }

    int lo = 1, hi = m - 1, ans = m;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    printf("%d\n", ans);

    check(ans, true);
}