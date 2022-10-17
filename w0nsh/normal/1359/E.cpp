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
int fact[500005];
int invfact[500005];

int binco(int n, int k){
	auto xd = (1ll*fact[n]*invfact[n-k])%MOD;
	return (1ll*xd*invfact[k])%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = invfact[0] = 1;
	REP(i, 1, 500005){
		fact[i] = (1ll*fact[i-1]*i)%MOD;
		invfact[i] = modpow(fact[i], MOD-2);
	}

	int n, k;
	std::cin >> n >> k;

	int ans = 0;

	int cur = 1;
	while(true){
		int mam = n/cur-1;
		if(mam < k-1) break;

		int tera = binco(mam, k-1);

		ans = (ans+tera)%MOD;

		cur++;

	}

	std::cout << ans << "\n";

	return 0;
}