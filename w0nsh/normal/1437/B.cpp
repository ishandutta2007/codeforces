#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		int ans = 0;
		int ans2 = 0;
		FOR(i, n-1){
			if(s[i] == s[i+1] && s[i] == '1') ans++;
			if(s[i] == s[i+1] && s[i] == '0') ans2++;
		}
		std::cout << std::max(ans, ans2) << "\n";
	}
	return 0;
}