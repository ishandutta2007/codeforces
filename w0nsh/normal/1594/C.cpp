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
		char c;
		std::cin >> n >> c;
		std::string s;
		std::cin >> s;

		bool bad = false;
		FOR(i, n) if(s[i] != c) bad = true;
		if(!bad){
			std::cout << 0 << "\n";
			continue;
		}

		REP(i, 2, n+1){
			bad = false;
			for(int j = i; j <= n; j += i){
				if(s[j-1] != c) bad = true;
			}

			if(!bad){
				std::cout << "1\n" << i << "\n";
				break;
			}
		}
		if(!bad) continue;

		std::cout << "2\n" << n-1 << " " << n << "\n";
	}

	return 0;
}