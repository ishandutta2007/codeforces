#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int par[20][200005];
int lev[200005];
std::vector<VI> g;
void dfs(int v, int parent=-1){
  par[0][v] = parent;
  TRAV(ch, g[v]) if(ch != parent) lev[ch] = lev[v]+1, dfs(ch, v);
}

int lca(int a, int b){
  if(a == b) return a;
  if(lev[a] < lev[b]) std::swap(a, b);
  for(int l = 19; l >= 0; --l) if(lev[a] - (1<<l) >= lev[b]) a = par[l][a];
  if(a == b) return a;
  for(int l = 19; l >= 0; --l) if(par[l][a] != par[l][b]) a = par[l][a],
  b = par[l][b];
  return par[0][a];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
  int n, m;
  std::cin >> n >> m;
  g.resize(n);
  FOR(i, n-1){
    int a, b;
    std::cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  REP(l, 1, 20){
    FOR(i, n){
      if(par[l-1][i] == -1) par[l][i] = -1;
      else par[l][i] = par[l-1][par[l-1][i]];
    }
  }

  FOR(_, m){
    int k;
    std::cin >> k;
    VI A(k);
    int deep = -1;
    FOR(i, k){
      std::cin>> A[i];
      A[i]--;
      if(deep == -1 || lev[deep] < lev[A[i]]) deep = A[i];
    }
    bool bad = false;
    FOR(i, k){
      int lc = lca(deep, A[i]);
      if(lev[A[i]]-lev[lc] > 1){
        bad =true;
      }
    }
    if(bad) std::cout << "NO\n";
    else std::cout << "YES\n";
  }

	return 0;
}