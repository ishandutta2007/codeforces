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

int n, d, m;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> d >> m;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		bool in = true;
		if(a + b < d) in = false;
		if(std::abs(a-b) > d) in = false;
		if(a + b > 2*n-d) in = false;
		if(in) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}