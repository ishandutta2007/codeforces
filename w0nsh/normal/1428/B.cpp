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
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;

		bool cyc = true;
		FOR(i, n) if(s[i] != '>' && s[i] != '-') cyc = false;
		if(!cyc){
			cyc = true;
			FOR(i, n) if(s[i] != '<' && s[i] != '-') cyc = false;
		}
		if(cyc){
			std::cout << n << "\n";
		}else{
			int cnt = 0;
			FOR(i, n){
				char my = s[i];
				char nxt = s[(i+1)%n];
				if(my == '-' || nxt == '-') cnt++;
			}
			std::cout << cnt << "\n";
		}
	}

	return 0;
}