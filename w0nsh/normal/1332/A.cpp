#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int dy = d-c;
		int dx = b-a;
		bool good = true;
		if(y1 == y && y2 == y && (c != 0 || d != 0)) good = false;
		if(x1 == x && x2 == x && (a != 0 || b != 0)) good = false;
		if(y + dy < y1 || y + dy > y2) good = false;
		if(x + dx < x1 || x + dx > x2) good = false;
		std::cout << (good ? "YES" : "NO") << "\n";
	}

	return 0;
}