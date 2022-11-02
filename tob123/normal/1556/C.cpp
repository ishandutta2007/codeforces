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
  int N;
  cin >> N;
  vector<ll> C(N);
  for(int i=0; i<N; i++){
    cin >> C[i];
  }
  ll res = 0;
  for(int i=0; i<N-1; i+=2){
    ll curS = 0;
    ll lft = C[i];
    //cout << "starting " << i << endl;
    for(int j=i+1; j<N; j++){
      if(lft < 0)
        break;
      if(j%2 == 1){
        if(curS - C[j] <= 0){
          //cout << "s: " << curS << endl;
          ll x = min(lft, C[j]-curS);
          if(curS != 0)
            x++;
          //cout << "- " << j << ": " << x << endl;
          res += x;
        }
      }
      if(j%2 == 0)
        curS += C[j];
      else
        curS -= C[j];
      if(curS < 0){
        lft += curS;
        curS = 0;
      }
    }
  }
  cout << res << "\n";
}