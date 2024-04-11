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
	int t;
	std::cin >> t;
	while(t--){
		ll n;
		std::cin >> n;
		std::vector<ll> A(n);
		FOR(i, n) std::cin >> A[i];
		int ans = 0;
		ll mx = A[0];
		REP(i, 1, n){
			mx = std::max(mx, A[i]);
			ll roz = mx-A[i];
			int cnt = 0;
			while(roz > 0){
				cnt++;
				roz >>= 1;
			}
			ans = std::max(ans, cnt);
		}
		std::cout << ans << "\n";
	}
	return 0;
}