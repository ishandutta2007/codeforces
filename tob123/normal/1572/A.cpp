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

vector<vector<int>> G;
vector<int> res;

void dfs(int cur){
  res[cur] = -2;
  int erg = 1;
  for(int x : G[cur]){
    if(res[x] == -2){
      return;
    }
    else if(res[x] == -1){
      dfs(x);
    }
    int z = res[x];
    if(x > cur)
      z++;
    erg = max(erg, z);
  }
  res[cur] = erg;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    G.clear(); G.resize(N);
    res.resize(N);
    for(int i=0; i<N; i++){
      int k; 
      cin >> k;
      for(int j=0; j<k; j++){
        int x;
        cin >> x;
        x--;
        G[i].push_back(x);
      }
      res[i] = -1;
    }
    int erg = -1;
    for(int i=0; i<N; i++){
      if(res[i] == -1){
        dfs(i);
      }
      if(res[i] == -2){
        erg = -2;
        break;
      }
      erg = max(erg, res[i]);
    }
    if(erg == -2){
      cout << -1 << "\n";
    }
    else{
      cout << erg << "\n";
    }
  }
}