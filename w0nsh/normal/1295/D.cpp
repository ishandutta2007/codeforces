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

ll solve(ll u, ll m){
	std::vector<ll> p;
	ll cur = m;
	for(int i = 2; i <= 100000; ++i){
		if(cur%i == 0){
			p.push_back(i);
			while(cur%i == 0) cur /= i;
		}
	}
	if(cur != 1) p.push_back(cur);
	ll cnt = 0;
	FOR(mask, (1<<SZ(p))){
		cur = 1;
		FOR(j, SZ(p)) if(mask & (1<<j)){
			cur *= p[j];
		}
		if(__builtin_popcount(mask)%2 == 0){
			cnt += u/cur;
		}else{
			cnt -= u/cur;
		}
	}
	return cnt;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll a, m;
		std::cin >> a >> m;
		ll d = std::__gcd(a, m);
		a /= d;
		m /= d;
		std::cout << solve(a+m-1, m) - solve(a-1, m) << "\n";
	}
	return 0;
}