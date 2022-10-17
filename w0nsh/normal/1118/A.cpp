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
	int q;
	std::cin >> q;
	while(q--){
		ll n, a, b;
		std::cin >> n >> a >> b;
		ll sum = 0;
		if(n % 2 == 1) sum += a;
		n /= 2;
		sum += std::min(a*n*2, b*n);
		std::cout << sum << "\n"; 
	}
	return 0;
}