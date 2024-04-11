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

int n, m;
std::vector<ll> rests;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	VI cycle;
	rests.resize(m);
	if(m == 1){
		std::cout << 1ll*n*n;
		return 0;
	}
	REP(i, 1, m+1){
		cycle.push_back(1ll*i*i%m);
	}
	FOR(i, m){
		rests[cycle[i]] += n/m + (n%m > i ? 1 : 0);
	}
	ll ans = 0;
	rests.push_back(rests[0]);
	FOR(i, m){
		ans += rests[i]*rests[m-i];
	}
	std::cout << ans << "\n";
	return 0;
}