#include <bits/stdc++.h>
using namespace std;

struct MinCostFlow {
    typedef int cap_t;
    typedef int cost_t;
    bool iszerocap(cap_t cap) { return cap == 0; }
    struct edge {
        int target;
        cost_t cost;
        cap_t residual_capacity;
        cap_t orig_capacity;
        size_t revid;
    };
    int n;
    vector<vector<edge>> graph;
    MinCostFlow(int n) : graph(n), n(n) {}
    void addEdge(int s, int e, cost_t cost, cap_t cap) {
        if (s == e) return;
        edge forward{ e, cost, cap, cap, graph[e].size() };
        edge backward{ s, -cost, 0, 0, graph[s].size() };
        graph[s].emplace_back(forward);
        graph[e].emplace_back(backward);
    }
    pair<cost_t, cap_t> augmentShortest(int s, int e, cap_t flow_limit) {
        auto infinite_cost = numeric_limits <cost_t >::max();
        auto infinite_flow = numeric_limits <cap_t >::max();
        vector<pair<cost_t, cap_t>> dist(n, make_pair(infinite_cost , 0));
        vector<int> from(n, -1), v(n);
        dist[s] = pair<cost_t, cap_t>(0, infinite_flow);
        queue<int> q;
        v[s] = 1; q.push(s);
        while(!q.empty()) {
            int cur = q.front();
            v[cur] = 0; q.pop();
            for (const auto& e : graph[cur]) {
                if (iszerocap(e.residual_capacity)) continue;
                auto next = e.target;
                auto ncost = dist[cur].first + e.cost;
                auto nflow = min(dist[cur].second, e.residual_capacity);
                if (dist[next].first > ncost) {
                    dist[next] = make_pair(ncost, nflow);
                    from[next] = e.revid;
                    if (v[next]) continue;
                    v[next] = 1; q.push(next);
                }
            }
        }
        auto p = e;
        auto pathcost = dist[p].first;
        auto flow = dist[p].second;
        if (iszerocap(flow)|| (flow_limit <= 0 && pathcost >= 0)) return pair<
            cost_t, cap_t>(0, 0);
        if (flow_limit > 0) flow = min(flow, flow_limit);
        while (from[p] != -1) {
            auto nedge = from[p];
            auto np = graph[p][nedge].target;
            auto fedge = graph[p][nedge].revid;
            graph[p][nedge].residual_capacity += flow;
            graph[np][fedge].residual_capacity -= flow;
            p = np;
        }
        return make_pair(pathcost * flow, flow);
    }
    pair<cost_t,cap_t> solve(int s, int e, cap_t flow_minimum = numeric_limits <
            cap_t>::max()) {
        cost_t total_cost = 0;
        cap_t total_flow = 0;
        for(;;) {
            auto res = augmentShortest(s, e, flow_minimum - total_flow);
            if (res.second <= 0) break;
            total_cost += res.first;
            total_flow += res.second;
        }
        return make_pair(total_cost, total_flow);
    }
};


char s[101];
int cnt[26];
int beauty[101];

int main()
{
    int n;
    scanf("%d%s",&n,s);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < n; i++) scanf("%d",&beauty[i]);

    MinCostFlow mcf(2 + 26 + 26 * n / 2 + n);
    for (int i = 0; i < 26; i++)
    {
        mcf.addEdge(0, i + 1, 0, cnt[i]);
        for (int j = 0; j < n / 2; j++)
        {
            mcf.addEdge(i + 1, 26 + n / 2 * i + j + 1, 0, 1);
            mcf.addEdge(26 + n / 2 * i + j + 1, mcf.n - n + j - 1, (i == s[j] - 'a') ? -beauty[j] : 0, 1);
            mcf.addEdge(26 + n / 2 * i + j + 1, mcf.n - j - 2, (i == s[n - j - 1] - 'a') ? -beauty[n - j - 1] : 0, 1);
        }
    }

    for (int i = 0; i < n; i++) mcf.addEdge(mcf.n - n + i - 1, mcf.n - 1, 0, 1);
    printf("%d\n", -mcf.solve(0, mcf.n - 1).first);
}