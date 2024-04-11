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

const ll INF = 1e17;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<ll> L(N), R(N), C(N);
    for(int i=0; i<N; i++){
      cin >> L[i] >> R[i] >> C[i];
    }
    vector<ll> res;
    int minL=0, maxR=0;
    for(int i=0; i<N; i++){
      ll cur = INF;
      if(L[i] >= L[minL] && R[i] <= R[maxR] && sz(res)){
        cur = min(cur, res.back());
      }
      if(L[i] <= L[minL] && R[i] >= R[maxR]){
        cur = min(cur, C[i]);
      }
      if(L[i] < L[minL] || (L[i] == L[minL] && C[i] < C[minL]))
        minL = i;
      if(R[i] > R[maxR] || (R[i] == R[maxR] && C[i] < C[maxR]))
        maxR = i;
      cur = min(cur, C[minL] + C[maxR]);
      res.push_back(cur);
    }
    for(auto x : res){
      cout << x << "\n";
    }
  }
}