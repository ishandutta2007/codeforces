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

const ll MOD = 998244353;
const int n = 1e6+10;

int N;
ll dp[n];
ll p[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<ll> X(N+1), Y(N+1), S(N+1);
  for(int i=1; i<=N; i++){
    cin >> X[i] >> Y[i] >> S[i];
  }
  X[0] = Y[0] = S[0] = dp[0] = p[0] = 0;
  for(int i=1; i<=N; i++){
    auto it = lower_bound(X.begin(), X.end(), Y[i]);
    it--;
    int l = distance(X.begin(), it);
    dp[i] = (5*MOD + X[i]-Y[i] + p[i-1]-p[l])%MOD;
    p[i] = (p[i-1]+dp[i])%MOD;
  }
  ll sum = (X[N]+1) % MOD;
  for(int i=1; i<=N; i++){
    if(S[i])
      sum = (sum + dp[i]) % MOD;
  }
  cout << sum << endl;
}