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

const int n = 1e6+10;

int N;
int A[n], nxt[n];
unordered_map<int,vector<int>> G;
unordered_map<ll, vector<int>> M;
vector<int> V;
bool used[n];
int mm;

void dfs(int cur){
  int ind = A[cur]&((1<<mm)-1);
  while(sz(G[ind])){
    int x = G[ind].back();
    G[ind].pop_back();
    if(!used[x]){
      used[x] = true;
      used[x^1] = true;
      dfs(x);
    }
  }
  V.push_back(ind);
}

bool pos(int mmmmm){
  mm = mmmmm;
  G.clear();
  for(int i=0; i<2*N; i++){
    G[A[i]&((1<<mm)-1)].push_back(nxt[i]);
    used[i] = false;
  }
  bool res = true;
  for(int i=0; i<2*N; i++){
    res &= sz(G[A[i]&((1<<mm)-1)])%2 == 0;
  }
  if(!res)
    return false;
  V.clear();
  dfs(0);
  //cout << mm << ": ";
  //print(V);
  if(sz(V) != N+1){
    return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[2*i] >> A[2*i+1];
    nxt[2*i] = 2*i+1;
    nxt[2*i+1] = 2*i;
  }
  int l=0, h=20;
  while(l < h){
    int m = (l+h+1)/2;
    if(pos(m)){
      l = m;
    }
    else{
      h = m-1;
    }
  }
  pos(l);
  cout << l << endl;
  for(int i=0; i<2*N; i++){
    G[A[i]&((1<<l)-1)].push_back(nxt[i]);
    M[(((ll)(A[i]&((1<<l)-1))) << 20) | (A[i^1]&((1<<l)-1))].push_back(i);
    used[i] = false;
  }
  for(int i=N-1; i>=0; i--){
    ll a = V[i+1], b=V[i];
    while(true){
      int x = M[(a << 20) | b].back();
      M[(a<<20) | b].pop_back();
      if(!used[x]){
        used[x] = true;
        used[x^1] = true;
        cout << x+1 << " " << (x^1)+1 << " ";
        break;
      }
    }
  }
  cout << endl;
}