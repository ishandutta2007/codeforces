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
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	ll mx = 0;
	ll dd = 0;
	std::set<ll> set;
	FOR(i, n) set.insert(i+1);

	VI ans(n);

	FOR(i, n){
		ll cur = A[i] + dd;
		ll need = mx - cur;
		auto it = set.lower_bound(need);
		assert(it != set.end());
		dd += *it;
		ans[*it - 1] = i;
		mx = A[i] + dd;
		set.erase(it);
	}

	FOR(i, n) std::cout << ans[i]+1 << " ";
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}