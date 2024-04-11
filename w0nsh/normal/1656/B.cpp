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
	ll n, k;
	std::cin >> n >> k;
	std::vector<ll> A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());

	FOR(i, n){
		ll need = A[i] - k;
		auto it = std::lower_bound(A.begin(), A.end(), need);
		if(it != A.end() && *it == need){
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}