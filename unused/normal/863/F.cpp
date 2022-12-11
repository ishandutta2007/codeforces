#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// MinCostFlow mcf(n);
// for(each edges) mcf.addEdge(from, to, cost, capacity);
// mcf.solve(source, sink); // min cost max flow
// mcf.solve(source, sink, 0); // min cost flow
// mcf.solve(source, sink, goal_flow); // min cost flow with total_flow >= goal_flow if possible
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

int low[55], high[55];

int main()
{
    int n, q;
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++) low[i] = 1, high[i] = n;
    for (int i = 0; i < q; i++)
    {
        int t, l, r, v;
        scanf("%d%d%d%d",&t,&l,&r,&v);
        if (t == 1)
        {
            while (l <= r)
            {
                low[l] = max(low[l], v);
                ++l;
            }
        }
        else
        {
            while (l <= r)
            {
                high[l] = min(high[l], v);
                ++l;
            }
        }
    }

    MinCostFlow mcf(2 + n + n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mcf.addEdge(0, i, j * j - (j - 1) * (j - 1), 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = low[i]; j <= high[i]; j++)
        {
            mcf.addEdge(j, i + n, 0, 1);
        }
    }

    for (int i = 1; i <= n; i++) mcf.addEdge(n + i, n + n + 1, 0, 1);

    auto res = mcf.solve(0, n + n + 1);

    if (res.second != n) printf("-1\n");
    else printf("%d\n", res.first);
}