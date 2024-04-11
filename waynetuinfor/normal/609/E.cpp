#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5, lg = 18;

struct Edge {
  int id, from, to, cost;
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
} edge[maxn];

vector<Edge> G[maxn], E, MST[maxn];
int N, M, a, b, c, djs[maxn], dep[maxn], p[lg][maxn], dis[lg][maxn];
long long mst;
bool T[maxn];

void Kruskal();
int F(int);
void DFS(int, int, int, int);
long long LCA(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) djs[i] = i;
  for (int i = 1; i <= M; ++i) {
    cin >> a >> b >> c;
    G[a].push_back((Edge){ i, a, b, c });
    G[b].push_back((Edge){ i, b, a, c });
    E.push_back((Edge){ i, a, b, c });
    edge[i] = (Edge){ i, a, b, c };
  }
  Kruskal();
  DFS(1, 0, 0, 0);
  for (int i = 1; i <= M; ++i) {
    if (T[i]) cout << mst << '\n';
    else cout << mst - LCA(edge[i].from, edge[i].to) + edge[i].cost << '\n';
  }
  return 0;
}

void Kruskal() {
  sort(E.begin(), E.end());
  int node = 1;
  for (auto e : E) {
    if (node == N) return;
    int f = F(e.from), t = F(e.to);
    if (f == t) continue;
    MST[f].push_back((Edge){ 1, f, t, e.cost });
    MST[t].push_back((Edge){ 1, t, f, e.cost });
    djs[f] = t;
    T[e.id] = true;
    mst += e.cost;
    node++;
  }
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void DFS(int x, int fa, int d, int cost) {
  dep[x] = d;
  p[0][x] = fa;
  dis[0][x] = cost;
  for (int k = 1; k < lg; ++k) {
    if ((1 << k) > dep[x]) continue;
    p[k][x] = p[k - 1][p[k - 1][x]];
    dis[k][x] = max(dis[k - 1][x], dis[k - 1][p[k - 1][x]]);
  }
  for (auto e : MST[x]) if (e.to != fa) {
    DFS(e.to, x, d + 1, e.cost);
  }
}

long long LCA(int a, int b) {
  long long ret = 0;
  if (dep[a] > dep[b]) swap(a, b);
  for (int k = 0; k < lg; ++k) {
    if ((dep[b] - dep[a]) >> k & 1) ret = max(ret, (long long)dis[k][b]), b = p[k][b];
  }
  if (a == b) return ret;
  for (int k = lg - 1; k >= 0; --k) {
    if (p[k][a] != p[k][b]) {
      ret = max({ ret, (long long)dis[k][a], (long long)dis[k][b] });
      a = p[k][a], b = p[k][b];
    }
    if (a == b) return ret;
  }
  ret = max({ ret, (long long)dis[0][a], (long long)dis[0][b] });
  return ret;
}