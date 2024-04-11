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

constexpr ll MOD = 1000000007;

ll modpow(ll a, ll e){
	ll ret = 1;
	while(e){
		if(e&1) ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int k;
	std::cin >> k;

	ll x = 6;
	FOR(i, k-1){
		ll y = (x * x) % MOD;

		ll xd = (y * modpow(3, MOD-2)) % MOD;
		x = (xd * 8) % MOD;
	}
	
	std::cout << x << "\n";

	return 0;
}