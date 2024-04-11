#include<cstdio>
#include<vector>

using namespace std;

struct edge {
  int src, dst;
  edge(int s, int d)
    : src(s), dst(d) { }
};
typedef vector<edge> vertex;
typedef vector<vertex> graph;

long long sol;
int n, k;

vector<int> dfs(const graph& g, int u, int p = -1)
{
  vector<int> cnt(k+1, 0);
  cnt[0] = 1;
  for(int i=0; i<(int)g[u].size(); ++i) {
    const edge e = g[u][i];
    if(e.dst == p) continue;
    vector<int> tmp = dfs(g, e.dst, u);
    for(int j=0; j<k; ++j)
      sol += tmp[j] * cnt[k-(j+1)];
    for(int j=0; j<k; ++j)
      cnt[j+1] += tmp[j];
  }
  return cnt;
}

int main()
{
  scanf("%d%d", &n, &k);

  graph g(n);
  for(int i=0; i<n-1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].push_back(edge(a, b));
    g[b].push_back(edge(b, a));
  }

  sol = 0;
  dfs(g, 0);

  printf("%I64d\n", sol);
  return 0;
}