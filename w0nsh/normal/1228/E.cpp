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

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e >>= 1;
	}
	return ret;
}

int fact[1000];
int invfact[1000];

int binco(int n, int k){
	int xd = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*xd*invfact[n-k])%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = invfact[0] = 1;
	REP(i, 1, 1000) fact[i] = (1ll*i*fact[i-1])%MOD, invfact[i] = modpow(fact[i], MOD-2);
	int n, k;
	std::cin >> n >> k;
	if(k == 1){
		std::cout << 1 << "\n";
		return 0;
	}
	
	int ans = 0;
	FOR(i, n){
		int cur = binco(n, i);
		FOR(j, i) cur = (1ll*cur*modpow(k-1, n))%MOD;
		int ways = 0;
		REP(j, 1, n-i+1){
			ways = (1ll*ways+1ll*binco(n-i, j)*modpow(k-1, n-i-j))%MOD;
		}
		ways = modpow(ways, n);
		cur = (1ll*cur*ways)%MOD;
		if(i%2 == 0) ans = (ans+cur)%MOD;
		else ans = (ans-cur)%MOD;
		if(ans < 0) ans += MOD;
	}
	std::cout << ans;

	return 0;
}