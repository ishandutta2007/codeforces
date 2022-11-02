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

vector<char> vis;
vector<vector<int>> G;

int dfs(int cur){
  int cnt = 1;
  vis[cur] = true;
  for(int i : G[cur]){
    if(!vis[i]){
      cnt += dfs(i);
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  string A, B;
  cin >> T;
  while(T--){
    cin >> N;
    cin >> A >> B;
    bool pos = true;
    G.resize(20);
    vis.resize(20);
    for(int i=0; i<20; i++){
      vis[i] = false;
      G[i].clear();
    }
    for(int i=0; i<N; i++){
      pos &= A[i] <= B[i];
      if(A[i] != B[i]){
        int a = A[i]-'a';
        int b = B[i]-'a';
        G[a].push_back(b);
        G[b].push_back(a);
      }
    }
    if(pos){
      int cnt = 0;
      for(int i=0;i<20;i++){
        if(!vis[i]){
          cnt += dfs(i) - 1;
        }
      }
      cout << cnt << "\n";
    }
    else{
      cout << -1 << "\n";
    }
  }
}