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

constexpr int INF = 1000000666;

void solve(){
	int n, x;
	std::cin >> n >> x;
	PII range = MP(INF, -INF);
	int ans = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		range.X = std::min(range.X, a);
		range.Y = std::max(range.Y, a);
		if(range.Y - range.X > 2 * x){
			ans++;
			range.X = range.Y = a;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}