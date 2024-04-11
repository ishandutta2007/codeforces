#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

typedef vector<int> vertex;
typedef vector<vertex> graph;

void visit(const graph& g, int v, int u, vector<vector<int> >& comp, stack<int>& roots, stack<int>& S, vector<bool>& ins, vector<int>& num, int& time)
{
  num[v] = ++time;
  S.push(v); ins[v] = true;
  roots.push(v);
  for(int i=0; i<(int)g[v].size(); ++i) {
    int w = g[v][i];
    if(num[w] == 0)
      visit(g, w, v, comp, roots, S, ins, num, time);
    else if(u != w && ins[w])
      while(num[roots.top()] > num[w]) roots.pop();
  }
  if(v == roots.top()) {
    comp.push_back(vector<int>());
    while(1) {
      int w = S.top(); S.pop(); ins[w] = false;
      comp.back().push_back(w);
      if(v == w) break;
    }
    roots.pop();
  }
}

void bridge(const graph& g, vector<vector<int> >& comp)
{
  const int n = g.size();
  vector<int> num(n);
  vector<bool> ins(n);
  stack<int> roots, S;
  int time = 0;
  for(int u=0; u<n; ++u)
    if(num[u] == 0)
      visit(g, u, n, comp, roots, S, ins, num, time);
}

struct query {
  int v, w, id;
  query(int v, int id)
    : v(v), w(-1), id(id) { }
};

int U[100050];

void init(int n)
{
  for(int i=0; i<n; ++i)
    U[i] = i;
}

int find(int x)
{
  if(U[x] == x)
    return x;
  return U[x] = find(U[x]);
}

void uni(int x, int y)
{
  U[find(x)] = find(y);
}

vector<vector<query> > qs;

void lca_visit(const graph& g, int u, int w, vector<int>& col, vector<int>& anc)
{
  anc[find(u)] = u;
  for(int i=0; i<(int)g[u].size(); ++i) {
    if(g[u][i] != w) {
      lca_visit(g, g[u][i], u, col, anc);
      uni(u, g[u][i]);
      anc[find(u)] = u;
    }
  }
  col[u] = 1;
  for(int i=0; i<(int)qs[u].size(); ++i)
    if(col[qs[u][i].v])
      qs[u][i].w = anc[find(qs[u][i].v)];
}

void lca(const graph& g)
{
  init(g.size());
  vector<int> col(g.size()), anc(g.size());
  lca_visit(g, 0, -1, col, anc);
}

int s[100050], l[100050], dep[100050];

void dfs(const graph& g, int v, int p, int d)
{
  dep[v] = d;
  for(int i=0; i<(int)g[v].size(); ++i)
    if(g[v][i] != p)
      dfs(g, g[v][i], v, d+1);
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  graph g(n);
  for(int i=0; i<m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<vector<int> > comp;
  bridge(g, comp);

  int v = comp.size();
  graph h(v);

  vector<int> comp_id(n);
  for(int i=0; i<v; ++i)
    for(int j=0; j<(int)comp[i].size(); ++j)
      comp_id[comp[i][j]] = i;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<(int)g[i].size(); ++j) {
      if(comp_id[i] != comp_id[g[i][j]]) {
	h[comp_id[i]].push_back(comp_id[g[i][j]]);
	h[comp_id[g[i][j]]].push_back(comp_id[i]);
      }
    }
  }

  for(int i=0; i<v; ++i) {
    sort(h[i].begin(), h[i].end());
    h[i].erase(unique(h[i].begin(), h[i].end()), h[i].end());
  }

  dfs(h, 0, -1, 0);

  int k;
  scanf("%d", &k);

  qs.resize(v);

  for(int i=0; i<k; ++i) {
    scanf("%d%d", &s[i], &l[i]);
    s[i]--; l[i]--;
    s[i] = comp_id[s[i]];
    l[i] = comp_id[l[i]];
    qs[s[i]].push_back(query(l[i], i));
    qs[l[i]].push_back(query(s[i], i));
  }

  lca(h);

  vector<int> ans(k, -1);
  for(int i=0; i<v; ++i)
    for(int j=0; j<(int)qs[i].size(); ++j)
      if(qs[i][j].w >= 0)
	ans[qs[i][j].id] = qs[i][j].w;

  for(int i=0; i<k; ++i)
    printf("%d\n", dep[s[i]] + dep[l[i]] - 2 * dep[ans[i]]);

  return 0;
}