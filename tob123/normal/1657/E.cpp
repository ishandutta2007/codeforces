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

const int MAXN = 251;
const ll MOD = 998244353;

ll dp[MAXN][MAXN];
ll fac[MAXN], invFac[MAXN];

ll pw(ll b, ll e){
  ll res = 1;
  for(ll i=1; i<=e; i<<=1){
    if(i&e)
      (res *= b) %= MOD;
    b = b*b%MOD;
  }
  return res % MOD;
}
ll inv(ll x){
  return pw(x, MOD-2);
}
ll choose(ll n, ll c){
  return fac[n]*invFac[c]%MOD*invFac[n-c]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = invFac[0] = 1;
  for(int i=1; i<MAXN; i++){
    fac[i] = fac[i-1]*i%MOD;
    invFac[i] = invFac[i-1]*inv(i)%MOD;
  }
  int N, K;
  cin >> N >> K;
  N--;
  for(int i=0; i<=K; i++){
    dp[0][i] = 1;
  }
  for(int n=1; n<=N; n++){
    for(int k=1; k<=K; k++){
      dp[n][k] = dp[n][k-1];
      for(int cnt=1; cnt<=n; cnt++){
        (dp[n][k] += choose(n, cnt) * pw(K-k+1, cnt*(cnt-1)/2+cnt*(n-cnt)) % MOD * dp[n-cnt][k-1]) %= MOD;;
      }
    }
  }
  cout << dp[N][K] << endl;
}