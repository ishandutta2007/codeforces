#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int a, b;
		std::cin >> a >> b;
		int ans = -1;
		if( a == 0 && b == 0) ans = 0;
		else if(a == b) ans = 1;
		else if(std::abs(a - b) % 2 == 0) ans = 2;
		else ans = -1;
		std::cout << ans << "\n";
	}

	return 0;
}