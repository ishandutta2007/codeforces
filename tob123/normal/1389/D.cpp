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
  ll N, K, l1, l2, r1, r2;
  cin >> T;
  while(T--){
    cin >> N >> K;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    if(l1 > l2)
      swap(l1,l2), swap(r1,r2);
    ll a = 0;
    ll stI = 0;
    if(l2 > r1)
      a = l2-r1;
    else{
      stI = min(r1,r2) - max(l1,l2);
    }
    ll b = max(r1,r2) - min(l1,l2) - stI;
    ll bst = 1e17;
    K -= N*stI;
    if(K <= 0){
      cout << 0 << "\n";
      continue;
    }
    for(ll i=1; i<=N; i++){
      ll res = a*i;
      ll lft = K;
      if(lft <= i*b){
        res += lft;
      }
      else{
        lft -= i*b;
        res += i*b;
        res += lft*2;
      }
      //cout << i << ": " << res << endl;
      bst = min(bst, res);
    }
    cout << bst << "\n";
  }
}