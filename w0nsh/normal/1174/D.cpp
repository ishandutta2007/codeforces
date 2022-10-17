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
	int n, x;
	std::cin >> n >> x;
	VI ans;
	std::set<int> can;
	REP(i, 1, (1<<n)) can.insert(i);
	can.erase(x);
	int xr = 0;
	while(SZ(can)){
		int nw = *can.begin();
		can.erase(can.begin());
		int my = xr^nw;
		ans.push_back(my);
		xr = nw;
		can.erase(x^xr);
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}