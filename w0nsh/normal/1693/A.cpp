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
		int n;
		std::cin >> n;
		ll sum = 0;
		bool was = false;
		bool good = true;
		FOR(i, n){
			int a;
			std::cin >> a;
			sum += a;
			if(sum <= 0){
				if(was && a != 0){
					good = false;
				}
				was = true;
			}
		}
		if(sum == 0 && good) std::cout << "Yes\n";
		else std::cout << "No\n";
	}

	return 0;
}