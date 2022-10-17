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
	int n, m;
	std::cin >> n >> m;
	std::vector<ll> A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	ll gc = A[1]-A[0];
	REP(i, 2, n) gc = std::__gcd(gc, A[i]-A[i-1]);
	FOR(i, m){
		ll p;
		std::cin >> p;
		if(gc % p == 0){
			std::cout << "YES\n" << A[0] << " " << i+1 << "\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}