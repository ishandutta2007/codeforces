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

constexpr int MOD = 1000000007;

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int fact[100005];
int invfact[100005];

int binco(int n, int k){
	ll xd = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*xd*invfact[n-k])%MOD;
}

void solve(){
	int n, k;
	std::cin >> n >> k;

	VI pref(n+4);

	REP(i, 1, n+1){
		ll av = n;
		av -= 1ll * (i-1) * (k-1);
		if(av < i) continue;
		int moz = binco(av, i);

		int dw = binco(n, i);

		pref[i] = (1ll*moz*modpow(dw, MOD-2))%MOD;
	}

	int ans = 0;
	REP(i, 1, n+1){
		int cur = (pref[i] - pref[i+1])%MOD;
		cur = (cur + MOD) % MOD;
		ans = (ans + 1ll*cur*i) % MOD;
	}

	std::cout << (ans+1)%MOD << "\n";

}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fact[0] = 1;
	invfact[0] = 1;
	REP(i, 1, 100005){
		fact[i] = (1ll*fact[i-1]*i)%MOD;
		invfact[i] = modpow(fact[i], MOD-2);
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}