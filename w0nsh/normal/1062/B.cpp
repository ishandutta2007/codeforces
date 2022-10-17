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

int lg(int a){
	bool perf = true;
	int ret = 0;
	while(a > 1){
		if(a % 2 != 0) perf = false; 
		ret++, a /= 2;
	}
	return ret + (perf ? 0 : 1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	if(n == 1){
		std::cout << 1 << " " << 0 << "\n";
		return 0;
	}
	int max = 0;
	int dv = 2;
	VI A;
	bool perf = true;
	int same = -1;
	while(n > 1){
		int cur = 0;
		while(n % dv == 0) cur++, n /= dv;
		max = std::max(max, cur);
		if(cur > 0) A.push_back(dv);
		if(cur > 0){
			if(same == -1) same = cur;
			if(cur != same) perf = false;
			if(__builtin_popcount(cur) != 1) perf = false;
		}
		dv++;
	}
	ll ans = 1;
	TRAV(i, A) ans *= i;
	ll ans2 = 0;
	if(!perf) ans2++;
	std::cout << ans << " " << (max == 1 ? 0 : lg(max) + ans2) << "\n";
	return 0;
}