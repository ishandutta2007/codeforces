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

const int MOD = 1000000007;

int mod_pow(int b, int e){
	if(e == 0) return 1;
	if(e == 1) return b;
	int t = mod_pow(b, e/2);
	return ((e % 2 == 1 ? 1ll*b : 1ll)*((1ll*t*t)%MOD))%MOD;
}

int fact[1000005], invfact[1000005];
int binco(int n, int k){
	return (1ll*((1ll*fact[n]*invfact[n-k])%MOD)*invfact[k])%MOD;
}

int n, m, ans;

inline int add(int a, int b){
	return (a+b)%MOD;
}
inline int mult(int a, int b){
	return (1ll*a*b)%MOD;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = invfact[0] = 1;
	REP(i, 1, 1000001) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = mod_pow(fact[i], MOD-2);
	std::cin >> n >> m;
	REP(i, 1, std::min(n-1, m+1)){
		// i krawedzi, i+1 wierzcholkow
		ans = add(ans, mult(mult(binco(m-1, i-1), fact[i-1]),
			mult(mod_pow(m, n-i-1), mult(i+1, mult(mod_pow(n, n-1-i-1), binco(n-2, i-1))))));
	}
	if(n-1 <= m) ans = add(ans, mult(binco(m-1, n-2), fact[n-2]));
	std::cout << ans;
	return 0;
}