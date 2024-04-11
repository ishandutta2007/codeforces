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

void solve(){
	int n;
	std::cin >> n;

	constexpr int INF = 1000000666;
	int min = INF;
	int max = -INF;
	int cmin = 0;
	int cmax = 0;

	int alt = 2 * INF;

	FOR(i, n){
		int l, r, c;
		std::cin >> l >> r >> c;

		if(l < min || r > max) alt = 2 * INF;

		if(min > l || (min == l && cmin > c)){
			cmin = c;
			min = l;
		}
		if(max < r || (max == r && cmax > c)){
			cmax = c;
			max = r;
		}

		if(l == min && r == max) alt = std::min(alt, c);

		std::cout << std::min(alt, cmin + cmax) << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}