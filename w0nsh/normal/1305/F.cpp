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

int n;
std::vector<ll> A;

int check(ll what){
	std::vector<ll> p;
	ll cur = 2;
	while(cur*cur <= what){
		if(what%cur == 0){
			while(what%cur == 0) what /= cur;
			p.push_back(cur);
		}
		cur++;
	}
	if(what > 1) p.push_back(what);
	ll best = n+5;
	TRAV(j, p){
		cur = 0;
		TRAV(i, A){
			if(i < j) cur += j-i;
			else{
				ll xd = i%j;
				cur += std::min(xd, j-xd);
			}
		}
		best = std::min(best, cur);
	}
	return best;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(0, n-1);
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	ll gc = A[0];
	FOR(i, n) gc = std::gcd(A[i], gc);
	if(gc != 1){
		std::cout << 0 << "\n";
		return 0;
	}
	int np = 0;
	FOR(i, n) if(A[i]%2 == 1) np++;
	int ans = np;
	FOR(_, 12){
		ll a = A[uid(rng)];
		if(a > 1) ans = std::min(ans, check(a-1));
		ans = std::min(ans, check(a));
		ans = std::min(ans, check(a+1));
	}
	std::cout << ans << "\n";
	return 0;
}