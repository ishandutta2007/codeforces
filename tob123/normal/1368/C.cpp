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

vector<pii> V;

void addTow(int base, int dir){
  V.push_back({base,dir});
  V.push_back({base,2*dir});
  V.push_back({2+base,dir});
  V.push_back({2+base,2*dir});
  V.push_back({1+base,2*dir});
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  if(N%2){
    for(int i=0; i<2*N-1; i++){
      V.push_back({i,0});
    }
    for(int i=0; i<N-1; i+=2){
      addTow(2*i, 1);
      addTow(2*i+2, -1);
    }
    V.push_back({-1,0});
    V.push_back({-1,-1});
    V.push_back({0,-1});
    V.push_back({2*N-1,0});
    V.push_back({2*N-1,1});
    V.push_back({2*N-2,1});
  }
  else{
    for(int i=-2; i<2*N+1; i++){
      V.push_back({i,0});
    }
    for(int i=0; i<N; i+=2){
      addTow(2*i, 1);
      addTow(2*i, -1);
    }
    for(int i=-2; i<2*N+1; i++){
      V.push_back({i, 4});
    }
    for(int j=1; j<4; j++){
      V.push_back({-2,j});
      V.push_back({2*N, j});
    }
  }
  cout << sz(V) << endl;
  for(auto p : V){
    cout << p.first << " " << p.second << "\n";
  }
}