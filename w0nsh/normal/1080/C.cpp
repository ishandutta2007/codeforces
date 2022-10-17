#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

PR<ll, ll> ile(int n, int m, bool start_x){
	ll xd = 1ll*n*m;
	if(xd%2 == 0) return MP(xd/2, xd/2);
	return (start_x ? MP(xd/2+1, xd/2) : MP(xd/2, xd/2+1));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll n, m;
		std::cin >> n >> m;
		ll x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		PR<ll, ll> board = ile(n, m, true);
		auto minus = ile(x2-x1+1, y2-y1+1, (x1+y1)%2 == 0);
		board.X -= minus.X;
		board.Y -= minus.Y;
		board.X += (x2-x1+1)*(y2-y1+1);
		ll bx1, bx2, by1, by2;
		std::cin >> bx1 >> by1 >> bx2 >> by2;
		minus = ile(bx2-bx1+1, by2-by1+1, (bx1+by1)%2 == 0);
		board.X -= minus.X;
		board.Y -= minus.Y;
		board.Y += (bx2-bx1+1)*(by2-by1+1);
		ll ix1, ix2, iy1, iy2;
		ix1 = std::max(bx1, x1);
		ix2 = std::min(bx2, x2);
		iy1 = std::max(by1, y1);
		iy2 = std::min(by2, y2);
		if(ix1 <= ix2 && iy1 <= iy2){
			minus = ile(ix2-ix1+1, iy2-iy1+1, (ix1+iy1)%2 == 0);
			board.X += minus.X;
			board.Y += minus.Y;
			board.X -= (ix2-ix1+1)*(iy2-iy1+1);
		}
		std::cout << board.X << " " << board.Y << "\n";
	}
	return 0;
}