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
		int n;
		std::cin >> n;
		std::cin >> s;
		std::string ans;
		FOR(i, SZ(s)){
			if(s[i] == 'U') ans.push_back('D');
			else if(s[i] == 'D') ans.push_back('U');
			else{
				i++;
				ans.push_back('L');
				ans.push_back('R');
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}