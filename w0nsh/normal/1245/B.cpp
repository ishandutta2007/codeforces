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
	int t;
	std::cin >> t;
	while(t--){
		int n, a, b, c;
		std::string s;
		std::cin >> n >> a >> b >> c >> s;
		std::string ret = "";
		FOR(i, n) ret.push_back('?');
		int wn = 0;
		FOR(i, n){
			if(s[i] == 'R' && b > 0){
				ret[i] = 'P';
				b--;
				wn++;
			}
			if(s[i] == 'P' && c > 0){
				ret[i] = 'S';
				c--;
				wn++;
			}
			if(s[i] == 'S' && a > 0){
				ret[i] = 'R';
				a--;
				wn++;
			}
		}
		if(wn >= (n+1)/2){
			std::cout << "YES\n";
			FOR(i, n){
				if(ret[i] == '?'){
					if(a > 0) (std::cout << "R"), --a;
					else if(b > 0) (std::cout << "P"), --b;
					else (std::cout << "S"), --c;
				}else std::cout << ret[i];
			}
			std::cout << "\n";
		}else{
			std::cout << "NO\n";
		}
	}
	return 0;
}