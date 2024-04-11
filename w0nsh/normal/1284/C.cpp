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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	VI fact(n+1);
	fact[0] = 1;
	REP(i, 1, n+1){
		fact[i] = (1ll*fact[i-1]*i)%m;
	}
	int ans = 0;
	FOR(i, n){
		int cr = (1ll*fact[n-i]*(n-i))%m;
		cr = (1ll*cr*fact[i+1])%m;
		ans = (1ll*ans+1ll*cr)%m;
	}
	std::cout << ans << "\n";
	return 0;
}