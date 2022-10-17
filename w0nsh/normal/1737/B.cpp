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

ll find(ll x, ll co){
	ll left = 1;
	ll right = 1000000005ll;
	while(left < right){
		ll mid = (left + right) / 2;
		if(mid * (mid + co) > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left - 1;
}

ll solve(ll x){
	return find(x, 0) + find(x, 1) + find(x, 2);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		ll l, r;
		std::cin >> l >> r;
		std::cout << solve(r) - solve(l-1) << "\n";
	}

	return 0;
}