#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
typedef std::pair<ll, ll> PLL;

PLL get(ll a){
	if(a == 0) return MP(0, 0);
	if(a == 4){
		return MP(3, 1);
	}
	if(a %2 == 1 || (a%4 == 0 && a != 4)){
		auto pr = get(a-1);
		std::swap(pr.X, pr.Y);
		pr.X++;
		return pr;
	}
	ll xd = a/2;
	a /= 2;
	auto pr = get(a);
	std::swap(pr.X, pr.Y);
	pr.X += xd;
	return pr;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::set<ll> set;
	ll xd = 1;
	while(xd < 1000000000ll*1000000000ll){
		xd *= 2;
		set.insert(xd-2);
	}

	int t;
	std::cin >> t;
	while(t--){
		ll a;
		std::cin >> a;
		std::cout << get(a).X << "\n";
	}

	return 0;
}