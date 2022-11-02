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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while(TT--){
    ll N;
    cin >> N;
    vector<ll> T(N+1), X(N+1);
    for(ll i=0; i<N; i++){
      cin >> T[i] >> X[i];
    }
    T[N] = 2e11;
    ll curT = 0, curX = 0;
    ll dir = 0;
    ll suc = 0;
    for(ll i=0; i<N; i++){
      if(T[i] >= curT){
        curT = T[i] + abs(X[i]-curX);
        if(X[i] >= curX)
          dir = -1;
        else dir = 1;
        curX = X[i];
      }
      ll st = curX+dir*(curT-T[i]);
      ll nd = curX+dir*max(0ll,curT-T[i+1]);
      //cout << st << " - " << nd << endl;
      if(st > nd)
        swap(st, nd);
      if(st <= X[i] && nd >= X[i])
        suc++;
    }
    cout << suc << "\n";
  }
}