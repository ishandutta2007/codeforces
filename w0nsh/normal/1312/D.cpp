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

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int fact[200005], invfact[200005];

int binco(int n, int k){
	if(k > n || k < 0) return 0;
	int xd = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*xd*invfact[n-k])%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = invfact[0] = 1;
	REP(i, 1, 200005) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = modpow(fact[i], MOD-2);
	int n, m;
	std::cin >> n >> m;
	if(n == 2){
		std::cout << 0 << "\n";
		return 0;
	}
	int ans = (1ll*binco(m, n-1)*(n-1))%MOD;
	std::cerr << ans << std::endl;
	REP(i, 1, m+1){
		ans = (ans-binco(i-1, n-2))%MOD;
		if(ans < 0) ans += MOD;
	}
	std::cerr << ans << std::endl;
	ans = (1ll*ans*modpow(2, n-3))%MOD;
	std::cout << ans << "\n";
	return 0;
}