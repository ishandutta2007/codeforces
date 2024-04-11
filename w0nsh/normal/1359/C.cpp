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

bool operator <(PR<long double, ll> a, PR<long double, ll> b){
	if(std::abs(a.X-b.X) < 1e-15) return a.Y < b.Y;
	return a.X < b.X;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int c, h, want;
		std::cin >> h >> c>> want;

		c *= 2;
		h *= 2;
		want *= 2;

		int sr = (c+h)/2;

		if(want == h){
			std::cout << 1 << "\n";
			continue;
		}
		if(want <= sr){
			std::cout << 2 << "\n";
			continue;
		}

		ll left = 0;
		ll right = 100000000000ll;

		PR<long double, ll> best = MP((long double)std::abs(sr-want), 2);

		auto check = [&](ll m){
			long double up = m*(c+h) + h;

			up /= (2*m+1);

			best = std::min(best, MP(std::abs(up-want), 2*m+1));


			if(m*(c+h)+h > want*(2*m+1)) return true;
			return false;

		};

		while(right - left > 5){
			ll mid = (left+right)/2;

			if(check(mid)){
				left = mid+1;
			}else right = mid;
		}

		for(ll i = std::max(0ll, left-3); i < right + 3; ++i){
			check(i);
		}

		std::cout << best.Y << "\n";

	}

	return 0;
}