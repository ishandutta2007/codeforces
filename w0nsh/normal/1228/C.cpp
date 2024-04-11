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

int modpow(int a, ll e){
	int ret = 1;
	while(e > 0){
		if(e&1ll) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e >>= 1ll;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int x;
	ll n;
	std::cin >> x >> n;
	VI primes;
	int cur = x;
	for(int i = 2; i*i <= x; ++i){
		if(cur == 1) break;
		if(cur % i == 0) primes.push_back(i);
		while(cur % i == 0) cur /= i;
	}
	if(cur != 1) primes.push_back(cur);
	int ans = 1;
	TRAV(p, primes){
		ll cr = 1;
		ll ile = 0;
		while(((long double)cr) * p <= n + 5){
			cr = cr*p;
			ile += n/cr;
		}
		ans = (1ll*ans*modpow(p, ile))%MOD;
	}
	std::cout << ans;
	return 0;
}