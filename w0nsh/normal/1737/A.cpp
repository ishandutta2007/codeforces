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
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		VI cnt(26);
		TRAV(c, s){
			cnt[c-'a']++;
		}
		int ile = n / k;
		std::string ret;
		FOR(j, k){
			int pos = 0;
			int elo = 0;
			while(elo < ile && cnt[pos]){
				cnt[pos]--;
				pos++;
				elo++;
			}
			ret.push_back('a' + pos);
		}
		std::cout << ret << "\n";
	}

	return 0;
}