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
		std::string s;
		std::cin >> s;
		int have = 0;
		bool bad = false;
		TRAV(i, s){
			if(i == 'A') have++;
			else have--;
			if(have < 0) bad = true;
		}
		if(s[0] == 'B') bad = true;
		if(s.back() == 'A') bad = true;
		std::cout << (bad ? "NO\n" : "YES\n");
	}

	return 0;
}