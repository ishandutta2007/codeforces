#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 998244353;
const int MAX = 2e5+10;

ll N, M;

ll inv[MAX];
void precompute_inverse(int n, int mod) {
	inv[1]=1;
	for (int i=2; i<=n; i++)
		inv[i] = (mod - (mod/i)*1LL*inv[mod%i] % mod) % mod;
}
ll f[MAX], invF[MAX];

ll binom(ll a, ll b){
  if(a < 0 || a > b)
    return 0;
  return f[b] * invF[a] % MOD * invF[b-a] % MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  if(N == 2){
    cout << 0 << endl;
    return 0;
  }
  precompute_inverse(MAX-2, MOD);
  f[0] = invF[0] = 1;
  for(int i=1; i<MAX; i++){
    f[i] = f[i-1] * i;
    invF[i] = invF[i-1] * inv[i];
    f[i] %= MOD;
    invF[i] %= MOD;
  }
  /*
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      cout << binom(i,j) << " ";
    }
    cout << endl;
  }
  */
  ll res = 0;
  for(int i=1; i<=M; i++){
    res += binom(N-2, i-1) * (N-2);
    res %= MOD;
  }
  for(int i=0; i<N-3; i++){
    res *= 2;
    res %= MOD;
  }
  cout << res << endl;

  return 0;
}