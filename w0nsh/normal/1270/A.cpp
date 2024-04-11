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
		int n, a, b;
		std::cin >> n >> a >> b;
		int m1 = 0;
		int m2 = 0;
		FOR(i, a){
			int x;
			std::cin >> x;
			m1 = std::max(m1, x);
		}
		FOR(i, b){
			int x;
			std::cin >> x;
			m2 = std::max(m2, x);
		}
		if(m1 > m2) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}