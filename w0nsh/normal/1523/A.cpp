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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		std::string s;
		std::cin >> s;
		int lst = 0;
		FOR(i, n) if(s[i] == '1') lst++;
		FOR(_, m){
			std::string nw;
			nw.resize(n);
			int cnt = 0;
			FOR(i, n){
				int al = 0;
				if(i > 0 && s[i-1] == '1') al++;
				if(i < n-1 && s[i+1] == '1') al++;
				if(al == 1 || s[i] == '1') cnt++, nw[i] = '1';
				else nw[i] = '0';
			}

			s = nw;
			if(cnt == lst) break;
			lst = cnt;
		}

		std::cout << s << "\n";
	}

	return 0;
}