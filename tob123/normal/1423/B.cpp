#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

struct maximum_bipartite_matching {
  int nl, nr, mbm = 0;
  vector<bool> v;
  vector<int> ml, mr;
  vector<vector<int>>& e;
  maximum_bipartite_matching(int nl, int nr, vector<vector<int>> & e) : nl(nl), nr(nr), ml(nl, -1), mr(nr, -1), e(e) {
    int prv = 0;
    do {
      prv = mbm;
      v.assign(nr, false);
      for (int i = 0; i < nl; i++)
        if (ml[i] == -1)
          mbm += findPath(i);
    } while (mbm > prv);
  }
  bool findPath(int i) {
    for (int j : e[i])
      if (!v[j]) {
        v[j] = true;
        if (mr[j] == -1 || findPath(mr[j])) {
          ml[i] = j; mr[j] = i;
          return true;
        }
      }
    return false;
  }
};

int N, M;
vector<tuple<int,int,int>> E;

vector<vector<int>> getE(int cnt){
  vector<vector<int>> e(2*N);
  for(int i=0; i<cnt; i++){
    auto [d, u, v] = E[i];
    e[u].push_back(v);
    e[v].push_back(u);
  }
  return e;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int u, v, d;
    cin >> u >> v >> d;
    E.emplace_back(d, u-1, v-1+N);
  }
  sort(E.begin(), E.end());
  auto res = getE(M);
  maximum_bipartite_matching m(N, 2*N, res);
  if(m.mbm < N){
    cout << -1 << "\n";
  }
  else{
    int l=0, r = M;
    while(l < r){
      int z = (l+r)/2;
      res = getE(z);
      maximum_bipartite_matching m2(N, 2*N, res);
      if(m2.mbm < N){
        l = z+1;
      }
      else{
        r = z;
      }
    }
    cout << get<0>(E[r-1]) << "\n";
  }
}