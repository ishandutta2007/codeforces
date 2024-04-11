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
		std::cin >> s;
		int fs = -1, ls = -1;
		int cnt = 0;
		FOR(i, SZ(s)){
			if(s[i] == '0'){
				if(fs == -1) fs = i;
				ls = i;
			}
			if(s[i] == '1') cnt++;
		}

		if(fs == -1) std::cout << 0 << "\n";
		else if(cnt == 0) std::cout << 1 << "\n";
		else{
			bool good = true;
			REP(j, fs, ls){
				if(s[j] == '1'){
					good = false;
					break;
				}
			}

			if(good) std::cout << 1 << "\n";
			else std::cout << 2 << "\n";
		}
	}

	return 0;
}