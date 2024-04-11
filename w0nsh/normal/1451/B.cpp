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
		int n, q;
		std::cin >> n >> q;
		std::string s;
		std::cin >> s;
		FOR(_, q){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			bool good = false;
			FOR(i, a) if(s[i] == s[a]) good = true;
			REP(i, b+1, n) if(s[i] == s[b]) good = true;
			std::cout << (good ? "YES\n" : "NO\n");
		}
	}
	return 0;
}