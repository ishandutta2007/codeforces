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
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		int xd[3];
		xd[0] = xd[1] = xd[2] = 0;
		FOR(i, n) xd[A[i]%3]++;
		int ans = xd[0];
		int min = std::min(xd[1], xd[2]);
		ans += min;
		xd[1] -= min;
		xd[2] -= min;
		if(xd[1] > 0) ans += xd[1]/3;
		if(xd[2] > 0) ans += xd[2]/3;
		std::cout << ans << "\n";

	}
	return 0;
}