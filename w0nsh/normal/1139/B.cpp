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
	int n;
	std::vector<ll> A;
	std::cin >> n;
	FOR(i, n){
		ll a;
		std::cin >> a;
		A.push_back(a);
	}
	ll ans = 0;
	ll mx = 2000000000ll;
	for(int i = n-1; i >= 0; --i){
		ans += std::min(A[i], mx);
		mx = std::max(0ll, std::min(A[i], mx)-1);
	}
	std::cout << ans;
	return 0;
}