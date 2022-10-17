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
typedef std::pair<ll, ll> PLL;

const ll MAX = 2500000000ll*10000000ll;

ll dist(PLL a, PLL b){
	return std::abs(a.X-b.X)+std::abs(a.Y-b.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll x0, y0, ax, ay, bx, by;
	std::cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	std::cin >> xs >> ys >> t;
	std::vector<PLL> A;
	while(x0 < MAX && y0 < MAX){
		A.push_back(MP(x0, y0));
		x0 = x0*ax + bx;
		y0 = y0*ay + by;
	}

	int ans = 0;
	FOR(i, SZ(A)){
		ll cost = 0;
		cost += dist(MP(xs, ys), A[i]);
		if(cost > t) continue;
		FOR(l, i+1){
			REP(r, i, SZ(A)){
				ll need = dist(A[i], A[l])+dist(A[i], A[r])+std::min(
				dist(A[i], A[l]),dist(A[i], A[r]));
				if(need+cost <= t) ans = std::max(ans, r-l+1);
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}