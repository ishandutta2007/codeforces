#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

ll n;
std::vector<ll> factors;

std::vector<ll> get_factors(ll num){
	std::vector<ll> ret;
	int cur = 2;
	while(num > 1 && cur < 100006){
		while(num % cur == 0) ret.push_back(cur), num /= cur;
		cur++;
	}
	if(SZ(ret) == 0) ret.push_back(num);
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int ans = 0;
	if(n % 2 != 0){
		factors = get_factors(n);
		ans++;
		n -= factors[0];
	}
	std::cout << ans + n/2 << "\n";
	return 0;
}