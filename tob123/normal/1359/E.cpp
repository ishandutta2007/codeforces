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

const int n = 5e5+10;
const int MOD = 998244353;

int N, K;
int dp[20][n];
ll F[n], F2[n];

int inv[n];
void precompute_inverse(int n, int mod) {
	inv[1]=1;
	for (int i=2; i<=n; i++)
		inv[i] = (mod - (mod/i)*1LL*inv[mod%i] % mod) % mod;
}

int ch(int n, int k){
  if(k > n)
    return 0;
  int res = F[n]*F2[n-k]%MOD*F2[k]%MOD;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  precompute_inverse(N, MOD);
  F[0] = 1; F2[0] = 1;
  for(int i=1; i<=N; i++){
    F[i] = F[i-1]*i % MOD;
    F2[i] = F2[i-1]*inv[i] % MOD;
  }
  if(K > N){
    cout << 0 << endl;
    return 0;
  }
  int sum = 0;
  for(int i=1; i<=N; i++){
    (sum += ch(N/i-1, K-1)) %= MOD;
  }
  cout << sum << endl;
}