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
  cin >> T;
  while(T--){
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll ma = a-1+b-1+c-1;
    ll sum = a+b+c;
    ll mx = max(a, max(b,c));
    sum -= mx;
    ll mi = max(0ll, mx - sum - 1);
    if(m >= mi && m <= ma){
      cout << "YES\n";
    }
    else
      cout << "NO\n";
  }
}