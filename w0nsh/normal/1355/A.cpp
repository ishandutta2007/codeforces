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

ll get(ll a){
	ll mn = a%10;
	ll mx = a%10;
	while(a > 0){
		mn = std::min(mn, a%10);
		mx = std::max(mx, a%10);
		a /= 10;
	}
	return mn*mx;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		ll a, k;
		std::cin >> a >> k;
		k--;
		FOR(i, std::min(k, 400ll)){
			a += get(a);
		}

		k -= std::min(k, 400ll);
		a += get(a)*k;

		std::cout << a << "\n";
	}


	return 0;
}