#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

#define MAXN 2020

int n, mat[MAXN], lev[MAXN];
bool ibg;
bitset<MAXN> v;
vector<int> vl, e[MAXN];

bool findPath(int i) {
  for (int j : e[i]) {
    if (v[j])
      continue;
    v[j] = true;
    if (mat[j] == -1 || findPath(mat[j])) {
      mat[i] = j; mat[j] = i;
      return true;
    }
  }
  return false;
}

void dfs(int i, int l = 1) {
  lev[i] = l;
  if (l == 1)
    vl.push_back(i);
  for (int j : e[i])
    if (!lev[j])
      dfs(j, 3 - l);
    else
      ibg = ibg && lev[i] != lev[j];
}

// get the size of the matching and the indices of the matched vertices
pair<int, vector<pair<int, int>>> maxCardinalityBipartiteMatching() {
  int mbm = 0, prev = 0;
  ibg = true;
  vl.clear();
  for (int i = 0; i < n; i++)
    mat[i] = -1, lev[i] = 0;
  for (int i = 0; i < n; i++)
    if (!lev[i])
      dfs(i);
  if (!ibg)
    return {-1, vector<pair<int, int>>()};
  do {
    prev = mbm;
    v.reset();
    for (int i : vl)
      if (mat[i] == -1)
        mbm += findPath(i);
  } while (mbm > prev);
  vector<pair<int, int>> ma;
  for (int i : vl)
    if (mat[i] != -1)
      ma.push_back({i, mat[i]});
  return {mbm, ma};
}

const int INF = 100000;
int N, M;
int S, B;
ll K, H;
int G[110][110];
vector<tuple<int,int,int>> sh;
vector<pair<int,int>> bases;

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      G[i][j] = INF;
    }
  }
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  cin >> S >> B >> K >> H;
  for(int i=0; i<S; i++){
    int x, a, f;
    cin >> x >> a >> f;
    x--;
    sh.push_back(make_tuple(x, a, f));
  }
  for(int i=0; i<B; i++){
    int x, d;
    cin >> x >> d;
    x--;
    bases.push_back(make_pair(x,d));
  }
  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
      }
    }
  }
  for(int i=0; i<S; i++){
    int xs, a, f;
    int xb, d;
    tie(xs, a, f) = sh[i];
    for(int j=0; j<B; j++){
      tie(xb, d) = bases[j];
      if(G[xs][xb] <= f && a >= d){
        e[i].push_back(S+j);
        e[S+j].push_back(i);
      }
    }
  }
  n = S+B;
  auto p = maxCardinalityBipartiteMatching();
  ll match = p.first;
  ll best = match*K;
  for(ll x=1; x<=S; x++){
    best = min(best, x*H + min(match, S-x)*K);
  }
  cout << best << endl;

  return 0;
}