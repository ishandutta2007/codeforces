#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

namespace debug {
  
template<class T> string _str(const T x) {ostringstream str; str << x; return str.str(); }
string _str(const bool x) {ostringstream str; str << (x ? "true" : "false"); return str.str(); }
string _str(const int x) {ostringstream str; str << x; return str.str(); }
string _str(const long long x) {ostringstream str; str << x; return str.str(); }
string _str(const char x) {ostringstream str; str << "'" << x << "'"; return str.str(); }
string _str(const string x) {ostringstream str; str << '"' << x << '"'; return str.str(); }
string _str(const double x) {ostringstream str; str.precision(6); str.setf(ios::fixed); str << x; return str.str(); }
string _str(const char* x) { return _str((string) x);}

template<class K, class V> string _str(const pair<K, V> x);
template<class T> string _str(const vector<T> x);
template<class T> string _str(const set<T> x);
template<class K, class V> string _str(const map<K, V> x);

template<class K, class V> string _str(const pair<K, V> x) {ostringstream str; str << '(' << _str(x.first) << ", " << _str(x.second) << ')'; return str.str();}   
template<class T> string _str(const vector<T> x) {ostringstream str; str << "["; for(int i = 0; i < x.size(); ++i) { if (i) str << ", "; str << _str(x[i]); } str << "] size " << x.size(); return str.str(); }
template<class T> string _str(const set<T> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it); } str << "} size " << x.size(); return str.str(); }
template<class K, class V> string _str(const map<K, V> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it.X) << " -> " << _str(it.Y); } str << "} size " << x.size(); return str.str(); }

void _dvar(bool isfirst, vector<string>::iterator it) {}
template<typename TCur, typename... TArgs>
void _dvar(bool isfirst, vector<string>::iterator it, TCur cur, TArgs... x) {if (!isfirst) cerr << " | "; cerr << *it << " = " << _str(cur); _dvar(false, ++it, x...); }

template<typename... TArgs>
void _d(string arg_names, TArgs... args) {
  int open = 0;
  vector<string> names;
  string cur;
  char wait_for_quote = 0;
  for (char c: arg_names) {
    if (c == ',' && open == 0 && !wait_for_quote) {
      names.pb(cur);
      cur = "";
    } else {
      cur += c;
      if (wait_for_quote) {
	if (wait_for_quote == c)
	  wait_for_quote = 0;
      } else {
	if (c == '\'' || c == '"') wait_for_quote = c; else {
	  if (c == '(') open++; else if (c == ')') open--;
	}
      }
    }
  }
  if (sz(cur)) {
    names.pb(cur);
  }
  _dvar(true, names.begin(), args...);
  cout << endl;
}
	
#ifdef LocalHost
#define D(x...) _d(#x, x)
// Use it as C(__LINE__)
#define C(line, x...) cout << __FILE__ << ":" << line << " "; D(x)
#else
#define D(x...);
#define C(x...);
#endif
} // ~namespace debug
using namespace debug;

vector<vector<int>> adj;
vector<int> t;
vector<int> low;
int globalt;
vector<int> st;
vector<int> change;
vector<int> add;
vector<bool> vis;

void go(int x, int par = -1) {
  t[x] = low[x] = ++globalt;
  st.pb(x);
  int saw = 0;
  for (int y: adj[x]) {
    if (!t[y]) go(y, x);

    if (y == par) saw++;
    if (y != par || saw > 1) { // !test
      if (x == 2) D(y, low[y], saw);
      low[x] = min(low[x], low[y]);
    }
  }
  if (low[x] >= t[x]) {
    vector<int> comp;
    while (st.back() != x) {
      comp.pb(st.back());
      st.pop_back();
    }
    st.pop_back();
    comp.pb(x);
    REP (i, sz (comp)) {
      change[comp[i]] = comp[0];
    }
    D(comp);
  }
}

namespace LCAOffline
{
  const int V = 200000;
    
  template <int N>
  struct Disjoint {
    int rank[N], p[N], n;   
    int findset(int q) {
      int r = q, t;
      while (p[r] != r) r = p[r];
      while (p[q] != q) { t = p[q]; p[q] = r; q = t;  }
      return r;
    }
    void join(int q, int w) {
      q = findset(q);
      w = findset(w);
      if (rank[q] < rank[w]) p[q] = w; else {
	p[w] = q;
	if (rank[q] == rank[w]) rank[w]++;
      }
    }    
    void init (int _n) {
      n = _n;
      REP(i, n) { p[i] = i; rank[i] = 0; }
    }
  };

  vector<vi> adj;
  vector <vector<pii>> queries;
  vi anc, res;
  vector <int> comp;
  int comps;
  int n;
  Disjoint <V> ds;
    
  void dfs (int q, int from)
  {
    anc[q] = q;
    REP (i, sz (adj[q]))
      {
	int w = adj[q][i];
	if (w == from) continue;
	dfs (w, q);
	ds.join (q, w);
	anc[ds.findset (q)] = q;
      }
    comp[q] = comps;
    REP (i, sz (queries[q]))
      if (comp[queries[q][i].X] == comps) {
	res[queries[q][i].Y] = anc[ds.findset (queries[q][i].X)];
      }
  }
    
  vi build (const vector<vi>& iadj, const vector<pii>& iqueries)
  {
    adj = iadj;
    n = sz (adj);
    comp = vector <int> (n);
    queries = vector <vector<pii>> (n);
    REP (i, sz (iqueries))
      {
	queries[iqueries[i].X].pb (pii (iqueries[i].Y, i));
	queries[iqueries[i].Y].pb (pii (iqueries[i].X, i));
      }
    res = vi (sz (iqueries), -1);
    anc = vi (n);
    ds.init (n);
    comps = 0;
    REP (i, n) if (!comp[i]) {
      comps++;
      dfs (i, -1);
    }
    return res;
  }
};

bool dfs(int x, int par, vector<int>& up, vector<int>& down, vector<bool>& vis) {
  vis[x] = true;
  for (int y: adj[x]) if (y != par) {
      if (!dfs(y, x, up, down, vis)) {
	return false;
      }
      up[x] += up[y];
      down[x] += down[y];
  }
  if (up[x] && down[x]) {
    return false;
  }
  return true;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  std::ios_base::sync_with_stdio(false);
  int n, m, queries;
  cin >> n >> m >> queries;
  adj.resize(n);
  t.resize(n);
  low.resize(n);
  REP (i, m) {
    int q, w;
    cin >> q >> w;
    q--, w--;
    adj[q].pb(w);
    adj[w].pb(q);
  }
  change.resize(n);
  REP (i, n) if (!t[i]) {
    go(i);
  }
  D(t);
  D(low);
  vector<vector<int>> tadj(n);
  REP (i, n) {
    for (int j: adj[i])
      if (change[i] != change[j])
      tadj[change[i]].pb(change[j]);
  }
  adj.swap(tadj);
  REP (i, n) {
    sort(all(adj[i]));
    adj[i].resize(unique(all(adj[i])) - adj[i].begin());
  }
  REP (i, n) {
    D(i, adj[i]);
  }
  D(change);
  vector<pii> qp;
  vector<int> up(n), down(n);
  REP (i, queries) {
    int q, w;
    cin >> q >> w;
    --q, --w;
    q = change[q];
    w = change[w];
    qp.pb(pii(q, w));
    up[q]++;
    down[w]++;
  }
  vi lca = LCAOffline::build(adj, qp);
  REP (i, sz (lca)) {
    if (lca[i] == -1) {
      cout << "No" << endl;
      return 0;
    }
    up[lca[i]]--;
    down[lca[i]]--;
  }
  D(up);
  D(down);
  vector<bool> vis(n);
  REP (i, n) {
    if (!vis[i]) {
      if (!dfs(i, -1, up, down, vis)) {
	cout << "No" << endl;
	return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}