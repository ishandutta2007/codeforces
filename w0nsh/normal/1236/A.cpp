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
		int a, b, c;
		std::cin >>  a >> b >> c;
		int ans = 0;
		while(b > 0 && c > 1){
			ans += 3;
			b -= 1;
			c -= 2;
		}
		while(a > 0 && b > 1){
			ans += 3;
			a -= 1;
			b -= 2;
		}
		std::cout << ans << "\n";
	}
	return 0;
}