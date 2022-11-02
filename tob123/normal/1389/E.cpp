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
    ll M, D, W;
    cin >> M >> D >> W;
    /*
    if (M < 15 && D < 15){
      for(int i=0; i<M; i++){
        for(int j=0; j<D; j++){
          if(i < D && j < M && (i*D+j)%W == (j*D+i)%W)
            cout << "*";
          cout << (i*D+j)%W << "\t";
        }
        cout << endl;
      }
      cout << endl;
    }
    */
    ll K = min(M, D);
    if((D-1)%W == 0){
      cout << K*(K-1)/2 << "\n";
      continue;
    }
    W /= gcd(W, D-1);
    if(K <= W){
      cout << "0\n";
      continue;
    }
    ll a = K%W;
    ll b = W-a;
    ll x = K/W;
    //cout << K << " " << W << " " << a << " " << b << " " << x << endl;
    ll res = b * (x*(x-1)/2) + a*(x*(x+1)/2);
    cout << res << "\n";
  }
}