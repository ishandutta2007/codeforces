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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;
		s = "R" + s + "R";
		int last = -1;
		int max = 0;
		FOR(i, SZ(s)){
			if(s[i] == 'R'){
				max = std::max(i-last, max);
				last = i;
			}
		}
		std::cout << max << "\n";
	}
	return 0;
}