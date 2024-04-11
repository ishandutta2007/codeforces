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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<ll> A(n);
		ll sum = 0;
		FOR(i, n) std::cin >> A[i], sum += A[i];
		ll mx = 0;
		ll s = 0;
		FOR(i, n-1){
			s = std::max(s+A[i], A[i]);
			mx = std::max(s, mx);
		}
		s = 0;
		REP(i, 1, n){
			s = std::max(s+A[i], A[i]);
			mx = std::max(s, mx);
		}
		if(sum > mx) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
	return 0;
}