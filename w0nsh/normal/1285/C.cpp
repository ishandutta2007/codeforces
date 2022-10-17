#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
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
	ll x;
	std::cin >> x;
	std::vector<ll> fac;
	ll cur = 2;
	ll oldx = x;
	while(cur*cur <= oldx && x > 1){
		ll xd = 1;
		while(x % cur == 0) xd *= cur, x /= cur;
		if(xd != 1) fac.push_back(xd);
		cur++;
	}
	if(x != 1) fac.push_back(x);
	PR<ll, ll> best = MP(1000000000000000ll, 100000000000000ll);
	FOR(mask, 1<<SZ(fac)){
		ll a = 1;
		ll b = 1;
		FOR(i, SZ(fac)) ((mask & (1<<i)) ? a : b) *= fac[i];
		PR<ll, ll> cand = MP(std::max(a, b), std::min(a, b));
		best = std::min(best, cand);
	}
	std::cout << best.X << " " << best.Y << "\n";
	
	return 0;
}