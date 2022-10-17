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
		ll n;
		std::cin >> n;
		int d = 0;
		int t = 0;
		int f = 0;
		while(n % 2 == 0) d++, n /= 2;
		while(n % 3 == 0) t++, n /= 3;
		while(n % 5 == 0) f++, n /= 5;
		if(n != 1) std::cout << -1 << "\n";
		else{
			std::cout << d+2*t+3*f << "\n";
		}

	}
	return 0;
}