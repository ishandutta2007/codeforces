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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<ll> A(n);
	FOR(i, n) std::cin >> A[i];
	ll best = 1000000000ll*1000000000ll;

	FOR(s, n){
		ll ans = 0;
		ll have = 0;
		REP(i, s+1, n){
			ll ile = have / A[i] + 1;
			ans += ile;
			have = ile * A[i];
		}

		have = 0;
		for(int i = s-1; i >= 0; --i){
			ll ile = have / A[i] + 1;
			ans += ile;
			have = ile * A[i];
		}

		best = std::min(best, ans);
	}
	std::cout << best << "\n";


	return 0;
}