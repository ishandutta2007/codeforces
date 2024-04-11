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

int T, N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    vector<ll> u(N), s(N);
    vector<vector<ll>> U(N);
    ll tot = 0;
    for(int i=0; i<N; i++){
      cin >> u[i];
      u[i]--;
    }
    for(int i=0; i<N; i++){
      cin >> s[i];
      tot += s[i];
      U[u[i]].push_back(s[i]);
    }
    set<int> ind;
    for(int i=0; i<N; i++){
      sort(U[i].begin(), U[i].end());
      for(int j=1; j<sz(U[i]); j++){
        U[i][j] += U[i][j-1];
      }
      ind.insert(i);
    }
    for(int k=1; k<=N; k++){
      vector<int> toE;
      ll cur = tot;
      for(int x : ind){
        if(sz(U[x]) < k){
          toE.push_back(x);
          if(sz(U[x])){
            cur -= U[x].back();
            tot -= U[x].back();
          }
        }
        else{
          int m = sz(U[x])%k;
          if(m > 0)
          cur -= U[x][m-1];
        }
      }
      cout << cur << " ";
      for(int x : toE)
        ind.erase(x);
    }
    cout << "\n";
  }
}