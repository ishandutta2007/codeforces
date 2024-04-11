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
  ll T, x1, x2, y1, y2;
  cin >> T;
  while(T--){
    cin >> x1 >> y1 >> x2 >> y2;
    ll y = abs(y1-y2);
    ll x = abs(x1-x2);
    if(y > x)
      swap(y, x);
    if(y == 0){
      cout << x << "\n";
    }
    else{
      cout << x+y+2 << "\n";
    }
  }
}