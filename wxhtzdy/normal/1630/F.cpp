#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a[50005], id[50005];
vector<int> d[50005];

class matching {
  public:
  vector< vector<int> > g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;
  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was = vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }
  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }
  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }
  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }
  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), id[a[i]] = i;
	matching G(2 * n, 2 * n);
	rep(i, n) for(int x : d[a[i]]) if(id[x] != -1) {
		G.add(i, id[x]);
		G.add(i + n, id[x] + n);
	}
	rep(i, n) G.add(i + n, i);
	printf("%d\n", G.solve() - n);
	rep(i, n) id[a[i]] = -1;
}

int main()
{
	rep1(i, 50000) id[i] = -1;
	rep1(i, 50000) {
		for(int j = i + i; j <= 50000; j += i) d[j].push_back(i);
	}
	int T;
	scanf("%d", &T);
	while(T --) solve();	
	return 0;
}