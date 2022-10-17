#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;

int modpow(int a, ll e){
	int ret = 1;
	while(e > 0){
		if(e&1ll) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

// sum a^(2k+1) * b^(2n-(2k+1)) * C(2n, 2k+1) , from 0 to n-1


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, l, r;
	std::cin >> n >> m >> l >> r;
	int par = (r-l+1)/2;
	int npar = (r-l+1)/2;
	if((r-l+1)%2 == 1){
		if(l%2 == 0) par++;
		else npar++;
	}
	ll nm = 1ll*n*m;
	int ans = modpow((par+npar)%MOD, nm);
	if(nm % 2 == 0){
		int mn = modpow((par+npar)%MOD, nm);
		mn -= modpow(std::abs(par-npar)%MOD, nm);
		if(mn < 0) ans += MOD;
		mn = (1ll*mn*modpow(2, MOD-2))%MOD;
		ans = (ans-mn)%MOD;
		if(ans < 0) ans += MOD;
	}
	std::cout << ans << "\n";

	return 0;
}