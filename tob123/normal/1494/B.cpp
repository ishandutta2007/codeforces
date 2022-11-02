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
  int T, n, x[4];
  cin >> T;
  while(T--){
    cin >> n;
    for(int i=0; i<4; i++){
      cin >> x[i];
    }
    bool pos = false;
    for(int m=0; m<(1<<4); m++){
      bool p2 = true;
      for(int i=0; i<4; i++){
        int cnt = 0;
        cnt += (m>>i)&1;
        cnt += (m>>((i+1)%4))&1;
        p2 &= cnt <= x[i] && x[i]-cnt <= n-2;
      }
      pos |= p2;
    }
    if(pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}