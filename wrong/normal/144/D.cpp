#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

struct edge {
  int src, dst, len;
  edge(int s, int d, int l)
    : src(s), dst(d), len(l) { }
};
bool operator < (const edge& e, const edge& f)
{
  return e.len > f.len;
}
typedef vector<edge> vertex;
typedef vector<vertex> graph;

int U[100050], V[100050], W[100050];

vector<int> dijkstra(const graph& g, int s)
{
  const int n = g.size();
  vector<int> dist(n, 1000000000);
  priority_queue<edge> Q;
  dist[s] = 0;
  Q.push(edge(-2, s, 0));
  while(!Q.empty()) {
    const edge e = Q.top(); Q.pop();
    for(int i=0; i<(int)g[e.dst].size(); ++i) {
      const edge& f = g[e.dst][i];
      if(dist[f.dst] > e.len + f.len) {
	dist[f.dst] = e.len + f.len;
	Q.push(edge(e.dst, f.dst, e.len+f.len));
      }
    }
  }
  return dist;
}

int main()
{
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);
  graph g(n);
  for(int i=0; i<m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    g[u].push_back(edge(u, v, w));
    g[v].push_back(edge(v, u, w));
    U[i]=u; V[i]=v; W[i]=w;
  }
  vector<int> D = dijkstra(g, s-1);
  int L, S = 0;
  scanf("%d", &L);
  for(int i=0; i<m; ++i) {
    int u = D[U[i]], v = D[V[i]], up = 0, vp = 0;
    if(u<L && u+W[i]>L) {
      int p = L-u, q = W[i]-p;
      if(u+p <= v+q) S++, up=1;
    }
    if(v<L && v+W[i]>L) {
      int p = L-v, q = W[i]-p;
      if(v+p <= u+q) S++, vp=1;
    }
    if(up && vp && L-u+L-v == W[i]) S--;
  }
  for(int i=0; i<n; ++i)
    if(D[i] == L) S++;
  printf("%d\n", S);
  return 0;
}