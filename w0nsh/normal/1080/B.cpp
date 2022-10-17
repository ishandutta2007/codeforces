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

ll sum(ll a){
	if(a == 0) return 0;
	return (a%2 == 0 ? 1ll : -1ll)*(a+1)/2;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		ll l, r;
		std::cin >> l >> r;
		std::cout << sum(r) - sum(l-1) << "\n";
	}
	return 0;
}