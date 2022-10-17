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
		int ans = 0;
		REP(i, 1, SZ(s)){
			if(s[i] == s[i-1]){
				s[i] = '$';
				ans++;
			}else if(i > 1 && s[i] == s[i-2]){
				s[i] = '$';
				ans++;
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}