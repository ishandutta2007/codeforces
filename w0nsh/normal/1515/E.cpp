#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int MOD;

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*a*ret)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}


int dp[405][405];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n >> MOD;

	VI fact(n+5);
	VI invfact(n+5);
	fact[0] = invfact[0] = 1;
	REP(i, 1, n+5) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = modpow(fact[i], MOD-2);
	auto binco = [&](int nn, int k){
		auto xd = (1ll*fact[nn]*invfact[nn-k])%MOD;
		return (1ll*xd*invfact[k])%MOD;
	};

	VI mem(n+5, -1);
	mem[0] = 1;
	mem[1] = 1;
	auto full = [&](int sz){
		if(mem[sz] != -1) return mem[sz];

		int ret = 0;
		FOR(i, sz){
			ret = (ret + binco(sz - 1, i))%MOD;
		}
		return mem[sz] = ret;
	};

	dp[0][0] = 1;
	FOR(sz, n+1){
		FOR(ile, sz+1){
			if(sz == 0 && ile == 0) continue;

			dp[sz][ile] = 0;
			if(sz == ile) dp[sz][ile] = full(sz);
			REP(pref, 1, sz-1){
				if (ile >= pref)
					dp[sz][ile] = (dp[sz][ile] + 1ll*(1ll * full(pref) * dp[sz-1-pref][ile - pref] % MOD) * binco(ile, pref)) % MOD;
			}
		}
	}

	int sum = 0;
	FOR(i, n+1) sum = (sum + dp[n][i])%MOD;
	std::cout << sum << "\n";

	return 0;
}