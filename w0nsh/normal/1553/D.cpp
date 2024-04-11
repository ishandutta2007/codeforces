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

		std::vector<VI> where[2] = {std::vector<VI>(26), std::vector<VI>(26)};
		int ind = 0;
		TRAV(i, s){
			where[ind&1][i-'a'].push_back(ind);
			ind++;
		}

		int INF = SZ(s);
		int dp[2] = {-1, -1};
		ind = 0;
		TRAV(c, t){
			int next[2] = {INF, INF};

			FOR(p, 2){
				auto it = std::lower_bound(where[p^1][c-'a'].begin(), where[p^1][c-'a'].end(), dp[p]+1);
				if(it != where[p^1][c-'a'].end()){
					assert(s[*it] == c);
					next[p^1] = std::min(next[p^1], *it);
				}
			}

			FOR(p, 2) dp[p] = next[p];
			ind++;
		}

		if(dp[(SZ(s)&1)^1] < INF){
			std::cout << "YES\n";
		}else{
			std::cout << "NO\n";
		}
	}

	return 0;
}