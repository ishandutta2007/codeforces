#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int pref[26][200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		std::string str;
		std::cin >> str;
		FOR(c, 26) REP(i, 1, n+1) pref[c][i] = pref[c][i-1] + (str[i-1] == 'a'+c);
		std::vector<int> ans(26);
		FOR(i, m){
			int a;
			std::cin >> a;
			FOR(c, 26) ans[c] += pref[c][a];
		}
		FOR(c, 26) std::cout << ans[c] + pref[c][n] << " ";
		std::cout << "\n";
	}

	return 0;
}