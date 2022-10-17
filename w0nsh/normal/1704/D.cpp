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
	int n, m;
	std::cin >> n >> m;
	std::vector<__int128> sums;
	FOR(i, n){
		__int128 cur = 0;
		ll pref = 0;
		FOR(j, m){
			ll a;
			std::cin >> a;
			pref += a;
			cur += pref;
		}
		sums.push_back(cur);
	}
	auto xd = (int)std::distance(sums.begin(), std::min_element(sums.begin(), sums.end()));
	auto mn = *std::min_element(sums.begin(), sums.end());
	auto mx = *std::max_element(sums.begin(), sums.end());
	std::cout << xd+1 << " " << (ll)(mx - mn) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}