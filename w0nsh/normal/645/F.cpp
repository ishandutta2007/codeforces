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
const int N = 1000000;

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int fact[2*N+5], invfact[2*N+5];

int binco(int n, int k){
	if(k > n) return 0;
	int x = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*x*invfact[n-k])%MOD;
}

int n, k, q;
int p[N+5], d[N+5], c[N+5];
VI divs[N+5];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = invfact[0] = 1;
	REP(i, 1, 2*N+1) fact[i]= (1ll*fact[i-1]*i)%MOD, invfact[i] = modpow(fact[i], MOD-2);
	REP(i, 1, N+1){
		for(int j = i; j <= N; j += i){
			divs[j].push_back(i);
		}
	}
	std::cin >> n >> k >> q;
	FOR(i, n){
		int a;
		std::cin >> a;
		TRAV(x, divs[a]) d[x]++;
	}
	for(int i = N; i >= 1; --i){
		c[i] = binco(d[i], k);
		for(int j = 2*i; j <= N; j += i){
			c[i] -= c[j];
			if(c[i] < 0) c[i] += MOD;
		}
	}
	int ans = 0;
	REP(i, 1, N+1) ans = (1ll*ans+1ll*c[i]*i)%MOD;
	REP(i, 1, N+1){
		p[i] = i;
		TRAV(dv, divs[i]) if(dv != i) p[i] -= p[dv];
	}
	FOR(_, q){
		int a;
		std::cin >> a;
		TRAV(dv, divs[a]){
			int roz = (binco(d[dv]+1, k)-binco(d[dv], k))%MOD;
			if(roz < 0) roz += MOD;
			ans = (1ll*ans+1ll*roz*p[dv])%MOD;
			d[dv]++;
		}
		std::cout << ans << "\n";
	}
	return 0;
}