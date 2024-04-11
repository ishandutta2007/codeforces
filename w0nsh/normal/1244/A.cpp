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
		int a, b, c, d, k;
		std::cin >> a >> b >> c >> d >> k;
		int x = (a/c) + (a%c == 0 ? 0 : 1);
		int y = (b/d) + (b%d == 0 ? 0 : 1);
		if(x+y > k) std::cout << -1 << "\n";
		else std::cout << x << " " << y << "\n";
	}
	return 0;
}