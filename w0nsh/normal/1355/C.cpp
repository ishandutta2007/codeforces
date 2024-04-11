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

ll ciag(ll fs, ll las){
	return (fs+las)*(las-fs+1)/2;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll a, b, c, d;
	std::cin >> a >> b >> c >> d;

	ll ans = 0;

	REP(s, a, b+1){
		ll l1 = b;
		ll r1 = c;
		ll l2 = c-s;
		ll r2 = d-s;

		l1 = std::max(l1, l2);

		if(l1 <= r1){

			//std::cout << "od " << std::min(l1-l2, r2-l2+1) << " do " << std::min(r1, r2+1)-l2 << std::endl;
			if(l1 <= r2) ans += ciag(std::min(l1 - l2, r2-l2+1), std::min(r1, r2) - l2);

			if(r1 > r2){
				ans += 1ll*(r1-std::max(l1-1, r2))*(r2-l2+1);
			}

		}
	}

	std::cout << ans << "\n";

	return 0;
}