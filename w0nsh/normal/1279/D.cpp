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

int modpow(int a, int e){
	int ret = 1;
	while(e > 0){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<VI> A(n);
	std::map<int, int> map;
	FOR(i, n){
		int k;
		std::cin >> k;
		A[i].resize(k);
		FOR(j, k){
			std::cin >> A[i][j];
			map[A[i][j]]++;
		}
	}
	std::map<int, int> prob;
	FOR(i, n){
		TRAV(j, A[i]){
			prob[j] = (prob[j]+modpow(SZ(A[i]), MOD-2))%MOD;
		}
	}
	TRAV(i, prob) i.Y = (1ll*modpow(n, MOD-2)*i.Y)%MOD;
	int ans = 0;
	TRAV(i, prob){
		int good = (1ll*map[i.X]*modpow(n, MOD-2))%MOD;
		ans = (1ll*ans+1ll*i.Y*good)%MOD;
	}
	std::cout << ans << "\n";
	return 0;
}