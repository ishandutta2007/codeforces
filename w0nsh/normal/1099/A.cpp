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
	int w, h;
	std::cin >> w >> h;
	int u1, d1, u2, d2;
	std::cin >> u1 >> d1 >> u2 >> d2;
	while(h > 0){
		w += h;
		if(h == d1) w = std::max(0, w-u1);
		if(h == d2) w = std::max(0, w-u2);
		h--;
	}
	std::cout << w << "\n";
	return 0;
}