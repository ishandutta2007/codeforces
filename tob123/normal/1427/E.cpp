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

vector<ll> X;
vector<tuple<int,ll,ll>> Q;

ll add(ll x){
  for(ll z : X){
    if((z ^ x) < x){
      Q.emplace_back(1, x, z);
      x = min(x, (z^x));
    }
  }
  if(x > 0 && x < 1e17){
    for(int i=0; i<sz(X); i++){
      if(X[i] > (X[i]^x)){
        Q.emplace_back(1, X[i], x);
        X[i] = min(X[i], X[i]^x);
      }
    }
    X.push_back(x);
  }
  else x = 0;
  return x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll x;
  cin >> x;
  queue<ll> q;
  q.push(x);
  while(sz(q)){
    ll res = q.front();
    q.pop();
    //cout << res << endl;
    res = add(res);
    if(res){
      for(ll k : X){
        Q.emplace_back(0, k, res);
        q.push(k + res);
      }
    }
    if(res == 1){
      break;
    }
  }
  cout << sz(Q) << endl;
  for(auto [t, a, b] : Q){
    cout << a;
    if(t == 0){
      cout << " + ";
    }
    else
      cout << " ^ ";
    cout << b << "\n";
    /*
    if( t == 0)
      cout << a + b << endl;
    else
      cout << (a ^ b) << endl;
    */
  }
}