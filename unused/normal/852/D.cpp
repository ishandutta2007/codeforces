#include <bits/stdc++.h>
using namespace std;

int dist[606][606];
int flow[606];

struct MaxFlowDinic
{
  struct edge
  {
    int nxt;
    size_t inv;
    int res;
  };
  int n;
  vector<vector<edge>> graph;
  vector<int> q, l, start;
  void init(int z)
  {
    n = z;
    graph.resize(n);
    for (int i = 0; i < n ; i++)graph[i].clear();
  }

  void addedge(int s, int e, int cap)
  {
    edge forward{ e, graph[e].size(), cap};
    edge backward{ s, graph[s].size(), 0 };
    graph[s].push_back(forward);
    graph[e].push_back(backward);
  }

  bool assign_level(int src, int sink)
  {
    int t = 0;
    memset(&l[0], 0, sizeof(l[0]) * l.size());
    l[src] = 1;
    q[t++] = src;
    for (int h = 0; h < t && !l[sink]; h++)
    {
      int cur = q[h];
      for (const auto &e : graph[cur])
      {
        if (l[e.nxt] || e.res == 0) continue;
        l[e.nxt] = l[cur] + 1;
        q[t++] = e.nxt;
      }
    }
    return l[sink];
  }
  int blk_flow(int cur, int sink, int curr)
  {
    if (cur == sink) return curr;
    for (int& i = start[cur]; i < graph[cur].size(); i++)
    {
      auto& e = graph[cur][i];
      if (e.res == 0 || l[e.nxt] != l[cur] + 1) continue;
      if (int res = blk_flow(e.nxt, sink, min(e.res, curr)))
      {
        e.res -= res;
        graph[e.nxt][e.inv].res += res;
        return res;
      }
    }
    return 0;
  }

  int solve(int src, int sink)
  {
    q.resize(n);
    l.resize(n);
    start.resize(n);
    int ans = 0;
    while (assign_level(src, sink))
    {
      memset(&start[0], 0, sizeof(start[0]) * n);
      while (int flow = blk_flow(src, sink, INT_MAX))
      {
        ans += flow;
      }
    }return ans;
  }
};

int main()
{
  int v, e, n, k;
  scanf("%d%d%d%d",&v,&e,&n,&k);
  
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d",&x);
    --x;
    flow[x]++;
  }

  for (int i = 0; i < v; i++) for (int j = 0; j < v; j++) dist[i][j] = 1e9;
  for (int i = 0; i < v; i++) dist[i][i] = 0;

  for (int i = 0; i < e; i++)
  {
    int a, b, w;
    scanf("%d%d%d",&a,&b,&w);
    --a;--b;
    dist[a][b] = dist[b][a] = min(dist[b][a], w);
  }

  for (int k = 0; k < v; k++) for (int i = 0; i < v; i++) for (int j = 0; j < v; j++)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int lo = 0, hi = 1731311, ans = -1;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    MaxFlowDinic mf;
    mf.init(v * 2 + 2);
    for (int i = 0; i < v; i++) mf.addedge(0, i + 1, flow[i]);
    for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < v; j++)
      {
        if (dist[i][j] > mid) continue;
        mf.addedge(i + 1, j + v + 1, INT_MAX);
      }
    }
    for (int i = 0; i < v; i++) mf.addedge(v + i + 1, v + v + 1, 1);

    int res = mf.solve(0, v + v + 1);
    if (res >= k)
    {
      ans = mid;
      hi = mid - 1;
    }
    else lo = mid + 1;
  }

  printf("%d\n", ans);
}