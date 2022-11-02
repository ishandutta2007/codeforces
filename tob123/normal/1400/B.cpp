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
  int T;
  ll p, f, cnts, cntw, s, w;
  cin >> T;
  while(T--){
    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;
    if(s > w){
      swap(s,w);
      swap(cnts, cntw);
    }
    ll best = 0;
    for(int i=0; i<=cnts; i++){
      if(i * s > p)
        break;
      ll s2 = cnts - i;
      ll w2 = max(0ll, cntw - (p-i*s)/w);
      ll c = min(s2, f/s);
      s2 -= c;
      w2 = max(0ll, w2 - (f-c*s)/w);
      best = max(best, cnts-s2+cntw-w2);
    }
    cout << best << "\n";
  }
}