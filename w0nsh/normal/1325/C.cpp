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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::vector<PII> > g(n);
	std::vector<int> ans(n-1, -1);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(MP(b, i));
		g[b].push_back(MP(a, i));
	}
	int fre = 0;
	FOR(i, n){
		if(SZ(g[i]) > 2){
			TRAV(j, g[i]) ans[j.Y] = fre++;
			break;
		}
	}
	FOR(i, n) TRAV(j, g[i]) if(ans[j.Y] == -1) ans[j.Y] = fre++;
	FOR(i, n-1) std::cout << ans[i] << "\n";

	return 0;
}