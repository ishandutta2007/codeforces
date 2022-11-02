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

int N, M;
vector<set<int>> B, E;
//vector<int> cnt;
int C=-1;

void add(int c, int l, int r){
  C -= sz(B[c]);
  if(E[c].count(l-1)){
    E[c].erase(l-1);
  }
  else{
    B[c].insert(l);
  }
  if(B[c].count(r+1)){
    B[c].erase(r+1);
  }
  else{
    E[c].insert(r);
  }
  C += sz(B[c]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  B.resize(M);
  E.resize(M);
  for(int i=0; i<N; i++){
    int t;
    cin >> t;
    t--;
    add(t, i, i);
  }
  cout << C << "\n";
  for(int i=0; i<M-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(sz(B[a]) < sz(B[b])){
      swap(B[a], B[b]);
      swap(E[a], E[b]);
    }
    C -= sz(B[a]);
    C -= sz(B[b]);
    for(int x : B[b]){
      if(E[a].count(x-1))
        E[a].erase(x-1);
      else
        B[a].insert(x);
    }
    for(int x : E[b]){
      if(B[a].count(x+1))
        B[a].erase(x+1);
      else
        E[a].insert(x);
    }
    C += sz(B[a]);
    cout << C << "\n";
  }
}