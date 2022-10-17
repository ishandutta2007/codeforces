#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i] = (A[i] < 0 ? 1 : 0);
	int np = 0;
	int p = 1;
	ll ans = 0;
	int cur = 0;
	FOR(i, n){
		cur = (cur+A[i])%2;
		if(cur) ans += np, np++;
		else ans += p, p++;
	}
	std::cout << 1ll*n*(n+1)/2ll-ans << " " << ans << "\n";

	return 0;
}