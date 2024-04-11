#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;

int mod_pow(int b, int e){
	int r = 1;
	while(e > 0){
		if(e&1) r = (1ll*r*b)%MOD;
		b = (1ll*b*b)%MOD;
		e >>= 1;
	}
	return r;
}

int fact[1000005], invfact[1000005];
inline int falling(int n, int k){
	return (1ll*fact[n]*invfact[n-k])%MOD;
}
inline int binco(int n, int k){
	return (1ll*falling(n, k)*invfact[k])%MOD;
}

int n;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = 1;
	invfact[0] = 1;
	REP(i, 1, 1000005) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = mod_pow(fact[i], MOD-2);
	std::cin >> n;
	ll ans = fact[n];
	REP(i, 1, n-1){
		ll xd = (1ll*fact[i]*binco(n, i))%MOD;
		xd = (1ll*xd*(fact[n-i]-1))%MOD;
		ans = (1ll*ans + xd)%MOD;
	}
	std::cout << ans << "\n";
	return 0;
}