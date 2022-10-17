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

	int q;
	std::cin >> q;
	while(q--){
		std::string s, t;
		std::cin >> s >> t;
		bool ans = false;
		FOR(start, SZ(s)){
			FOR(right, SZ(s)+1){
				std::string have;
				int pos = start;
				int ile = right;
				while(pos < SZ(s) && ile > 0){
					ile--;
					have.push_back(s[pos++]);
				}
				pos -= 2;
				int left = SZ(t) - SZ(have);
				while(pos >= 0 && left > 0){
					left--;
					have.push_back(s[pos--]);
				}

				if(have == t){
					ans = true;
				}
			}
		}
		if(ans) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}