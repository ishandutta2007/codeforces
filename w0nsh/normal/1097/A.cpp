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
	std::string my;
	std::cin >> my;
	FOR(i, 5){
		std::string xd;
		std::cin >> xd;
		if(xd[0] == my[0] || xd[1] == my[1]){
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}