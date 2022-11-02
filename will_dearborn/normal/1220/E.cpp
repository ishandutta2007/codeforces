#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef VInt::iterator VIter;
typedef pair<int, int> PInt;
typedef vector<PInt> VPInt;
typedef vector<VPInt> VVPInt;
typedef VPInt::iterator VPIter;

VVInt graph;
VInt colors, parents, enter, leave, low, bcc;
int myTime = 0;
int newIndex = 0;

/*
 *   ,   enter, leave  low
 */
void visitLow(int u) {
  colors[u] = 1;
  low[u] = enter[u] = ++myTime;

  for(VIter it = graph[u].begin(); it != graph[u].end(); it++)
    if(colors[*it] == 0) {
      parents[*it] = u;
      visitLow(*it);
      low[u] = min(low[u], low[*it]);
    } else if(colors[*it] == 1 && *it != parents[u]) {
      low[u] = min(low[u], enter[*it]);
    }

  colors[u] = 2;
  leave[u] = ++myTime;      
}

/*
 *    ,   bcc
 */
void visitBCC(int u) {
  for(VIter it = graph[u].begin(); it != graph[u].end(); it++)
    if(parents[*it] == u) {
      bcc[*it] = (low[*it] < enter[u]) ? bcc[u] :         //    
        (low[*it] > enter[u]) ? -1 :             //    
        (newIndex++);                            //      
      visitBCC(*it);         
    }
}

/*
 *   BCC,   ,  -1,   
 * (u, v)    ,      
 */
int getBCC(int u, int v) {
  return bcc[(enter[u] > enter[v]) ? u : v];
}

/*
 *  :  n  m,  m  
 *  :  ,      
 */

int s;
vl w, p, sw, dyn, sz;
vvi g;
ll SUM = 0, MAX = 0;

void dfs(int v, int p) {
  dyn[v] = 0;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v);
    if (sz[nv] == 1) {
      dyn[v] = max(dyn[v], dyn[nv]);
    } else {
      sz[v] = 2;
    }
  }
  if (sz[v] == 1) {
    dyn[v] += sw[v];
    MAX = max(MAX, dyn[v]);
  } else {
    SUM += sw[v];
    MAX = max(MAX, dyn[v]);
  }
}

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  p[a] = b;
}
/*
void go(int v, int p, vii& bridges) {
  if (graph[v].size() > 2 || v == s) return;
  for (int nv : graph[v]) if (nv != p) {
    bridges.emplace_back(v, nv);
    go(nv, v, bridges);
  }
}*/

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  w.resize(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  vii e(m);
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from - 1].push_back(to - 1);
    graph[to - 1].push_back(from - 1);
    if (from > to) swap(from, to);
    e[i] = pii(from - 1, to - 1);
  }
  cin >> s; --s;

  //    ( enter  low)
  colors.assign(n, 0);
  parents.assign(n, -1);
  enter.resize(n);
  leave.resize(n);
  low.resize(n);
  for(int i = 0; i < n; i++)
    if(colors[i] == 0)
      visitLow(i);

  //    (  bcc)
  //    " " ,
  //       
  bcc.assign(n, -1);
  for(int i = 0; i < n; i++)
    if(parents[i] == -1)
      visitBCC(i);   

  //  
  VPInt bridges;
  VVPInt comps(newIndex);
  for(int i = 0; i < n; i++)
    for(VIter it = graph[i].begin(); it != graph[i].end(); it++)
      if(i < *it) {
        int id = getBCC(i, *it);
        ((id == -1) ? bridges : comps[id]).push_back(PInt(i, *it));
      }

  for (pii & p : bridges) {
    if (p.first > p.second) swap(p.first, p.second);
  }
  sort(bridges.begin(), bridges.end());

  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (pii p : e) if (!binary_search(bridges.begin(), bridges.end(), p)) {
    join(p.first, p.second);
  }
  s = getp(s);
  sw.assign(n, 0);
  sz.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    sw[getp(i)] += w[i];
    sz[getp(i)] += 1;
  }
  g.resize(n);
  for (pii p : bridges) {
    int a = getp(p.first), b = getp(p.second);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dyn.assign(n, 0);
  sz[s] = 2;
  dfs(s, -1);
  cout << SUM + MAX << endl;
}