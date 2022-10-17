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

constexpr int N = 500005;
constexpr int MOD = 1000000007;
int fact[N], invfact[N];

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*a*ret)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int binco(int n, int k){
	if(k < 0 || k > n) return 0;
	int a = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*a*invfact[n-k])%MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fact[0] = invfact[0] = 1;
	REP(i, 1, N) fact[i] = (1ll*fact[i-1] * i)%MOD, invfact[i] = modpow(fact[i], MOD-2);

	int n;
	std::cin >> n;
	VI A(n+1);
	FOR(i, n+1) std::cin >> A[i];
	int ans = 0;
	FOR(i, n+1){
		ans = (ans + binco(i + A[i], i + 1)) % MOD;
	}
	std::cout << ans << "\n";

	return 0;
}