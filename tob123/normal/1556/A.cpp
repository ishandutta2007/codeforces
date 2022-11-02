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
    ll a=0, b=0, c, d;
    cin >> c >> d;
    if(a+b > c+d || (a+b)%2 != (c+d)%2){
      cout << -1 << "\n";
    }
    else if(a == c && b == d)
      cout << 0 << "\n";
    else if(abs(c-a) == abs(b-d))
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}