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
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		PII xl = MP(-100000, 100000);
		PII yl = MP(-100000, 100000);
		FOR(i, n){
			int x, y;
			std::cin >> x >> y;
			int a;
			std::cin >> a;
			if(a == 0) xl.X = std::max(xl.X, x);
			std::cin >> a;
			if(a == 0) yl.Y = std::min(yl.Y, y);
			std::cin >> a;
			if(a == 0) xl.Y = std::min(xl.Y, x);
			std::cin >> a;
			if(a == 0) yl.X = std::max(yl.X, y);
		}
		if(xl.X > xl.Y || yl.X > yl.Y) std::cout << 0 << "\n";
		else std::cout << "1 " << xl.X << " " << yl.X << "\n";
	}
	return 0;
}