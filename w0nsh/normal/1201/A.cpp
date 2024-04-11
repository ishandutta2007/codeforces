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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> str;
	FOR(i, n){
		std::string s;
		std::cin >> s;
		str.push_back(s);
	}
	int ans = 0;
	FOR(i, m){
		int cur;
		std::cin >> cur;
		int best = 0;
		FOR(kt, 5){
			int ths = 0;
			FOR(j, n){
				if(str[j][i] == ('A'+kt)) ths++;
			}
			best = std::max(best, ths);
		}	
		ans += cur*best;
	}
	std::cout << ans;
	return 0;
}