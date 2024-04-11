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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, m, k, l;
	std::cin >> n >> m >> k >> l;
	if(l > n-k) std::cout << -1 << "\n";
	else{
		ll nw = l + k;
		ll can_give = (n/m)*m;
		if(can_give < nw) std::cout << -1 << "\n";
		else{
			std::cout << (nw / m) + (nw%m != 0 ? 1 : 0) << "\n"; 
		}
	}
	return 0;
}