#include <bits/stdc++.h>
 
using namespace std;
 using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define pi acos(-1.0)
#define df(s) {freopen("s.in", "r", stdin); freopen("s.out", "w", stdout);}
int max(int a,int b){if (a>b){return a;} else {return b;}}
int min(int a,int b){if (a<b){return a;} else {return b;}}

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector<vector<int> > g;
  int n;
  graph(int _n) : n(_n) { g.resize(n); }
  virtual int add(int from, int to, T cost) = 0;
};

// undirectedgraph
template <typename T>
class undirectedgraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undirectedgraph(int _n) : graph<T>(_n) {}
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

// blossom / find_max_unweighted_matching
template <typename T>
vector<int> find_max_unweighted_matching(const undirectedgraph<T> &g) {
  std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> match(g.n, -1);   // t
  vector<int> aux(g.n, -1);     // ??W?
  vector<int> label(g.n);       // "o" or "i"
  vector<int> orig(g.n);        // 
  vector<int> parent(g.n, -1);  // ??
  queue<int> q;
  int aux_time = -1;

  auto lca = [&](int v, int u) {
    aux_time++;
    while (true) {
      if (v != -1) {
        if (aux[v] == aux_time) {  // ??? ]NOLCA
          return v;
        }
        aux[v] = aux_time;
        if (match[v] == -1) {
          v = -1;
        } else {
          v = orig[parent[match[v]]];  // Ht??????
        }
      }
      swap(v, u);
    }
  };  // lca

  auto blossom = [&](int v, int u, int a) {
    while (orig[v] != a) {
      parent[v] = u;
      u = match[v];
      if (label[u] == 1) {  // l???"o" W?
        label[u] = 0;
        q.push(u);
      }
      orig[v] = orig[u] = a;  // ?
      v = parent[u];
    }
  };  // blossom

  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v];
      int next_v = match[pv];
      match[v] = pv;
      match[pv] = v;
      v = next_v;
    }
  };  // augment

  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    // l??? "o", ?H"0"N"o", "1"N"i"
    label[root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int u = e.from ^ e.to ^ v;
        if (label[u] == -1) {  // ??
          label[u] = 1;        // ?? "i"
          parent[u] = v;
          if (match[u] == -1) {  // t?
            augment(u);          // ?W??
            return true;
          }
          // wt? ?Oot??Jqueue ??
          label[match[u]] = 0;
          q.push(match[u]);
          continue;
        } else if (label[u] == 0 && orig[v] != orig[u]) {
          // w?? B??P?"o" N""
          int a = lca(orig[v], orig[u]);
          // LCA MZ?
          blossom(u, v, a);
          blossom(v, u, a);
        }
      }
    }
    return false;
  };  // bfs

  auto greedy = [&]() {
    vector<int> order(g.n);
    // ?? order
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);

    // ?iHt?t
    for (int i : order) {
      if (match[i] == -1) {
        for (auto id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if (match[to] == -1) {
            match[i] = to;
            match[to] = i;
            break;
          }
        }
      }
    }
  };  // greedy

  // @?l?t
  greedy();
  // ?t?W?
  for (int i = 0; i < g.n; i++) {
    if (match[i] == -1) {
      bfs(i);
    }
  }
  return match;
}


#define M 200

int n, m;
int a[M][M];

bool ok(int cnt) {
	undirectedgraph<int> g(n * 2 + m + cnt + 1);
	FOE(i, 1, n) FOE(j, 1, m) if (a[i][j]) {
		g.add(j, m + i, 1);
		g.add(j, m + n + i, 1);
	}
	
	FOE(i, 1, cnt) FOE(j, 1, m) g.add(m + 2 * n + i, j, 1);
	FOE(i, 1, n) g.add(m + i, m + n + i, 1);
  	auto blossom_match = find_max_unweighted_matching(g);
  	int ret = 0;
  	for (auto x : blossom_match) if (x != -1) ret++;
  	
  	ret /= 2;
  
  	return (ret == (n * 2 + m + cnt) / 2);
}

void solve() {
	scanf("%d%d", &n, &m);

	FOE(i, 1, n) {
		string x; cin >> x;
		
		FOE(j, 1, m) a[i][j] = (int)(x[j - 1] - '0');	
	}
	
	FOE(i, 0, m) if (ok(i)) {
		printf("%d\n", (m - i) / 2);	
		return;
	}
}

int main() {
	int t; scanf("%d", &t);
	
	FOE(i, 1, t) solve();
}