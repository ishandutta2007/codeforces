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
	ll n, m;
	std::cin >> n >> m;
	if(m == 0){
		std::cout << n << " " << n << "\n";
		return 0;
	}
	int min = std::max(0ll, n - 2*m);
	FOR(i, n+1){
		if(1ll*i*(i-1)/2 >= m){
			std::cout << min << " " << n-i << "\n";
			return 0;
		}
	}
	return 0;
}