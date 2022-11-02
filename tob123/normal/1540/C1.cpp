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

const int n = 102;
const int m = n*n+2;
const ll MOD = 1e9 + 7;

ll N, Q, X;
ll C[n], B[n];
ll p[n][m];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> C[i];
  }
  for(int i=0; i<N-1; i++){
    cin >> B[i];
  }
  cin >> Q;
  cin >> X;
  for(int i=max(0ll, X); i<=C[0]; i++){
    p[0][i] = 1;
  }
  ll pref = 0;
  ll p2 = 0;
  for(int k=1; k<N; k++){
    pref += B[k-1];
    p2 += pref;
    ll v = (k+1)*X + p2;
    for(int s=v; s<m; s++){
      for(int i=0; i<=min((ll)s, C[k]); i++){
        (p[k][s] += p[k-1][s-i]) %= MOD;
      }
    }
  }
  ll res = 0;
  for(int i=0; i<m; i++){
    res += p[N-1][i];
  }
  res %= MOD;
  cout << res << endl;
}