#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll inter(PII a1, PII a2, PII b1, PII b2){
	PII c1 = MP(std::max(a1.X, b1.X), std::max(a1.Y, b1.Y));
	PII c2 = MP(std::min(a2.X, b2.X), std::min(a2.Y, b2.Y));
	if(c1.X >= c2.X || c1.Y >= c2.Y) return 0ll;
	return 1ll*(c2.X-c1.X)*(c2.Y-c1.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	PII a1, a2;
	PII b1, b2, c1, c2;
	std::cin >> a1.X >> a1.Y >> a2.X >> a2.Y;
	std::cin >> b1.X >> b1.Y >> b2.X >> b2.Y;
	std::cin >> c1.X >> c1.Y >> c2.X >> c2.Y;
	b1.X = std::max(b1.X, a1.X);
	b1.Y = std::max(b1.Y, a1.Y);
	b2.X = std::min(b2.X, a2.X);
	b2.Y = std::min(b2.Y, a2.Y);
	c1.X = std::max(c1.X, a1.X);
	c1.Y = std::max(c1.Y, a1.Y);
	c2.X = std::min(c2.X, a2.X);
	c2.Y = std::min(c2.Y, a2.Y);
	ll i = inter(a1, a2, b1, b2)+inter(a1, a2, c1, c2)-inter(b1, b2, c1, c2);
	if(i == 1ll*(a2.X-a1.X)*(a2.Y-a1.Y)) std::cout << "NO\n";
	else std::cout << "YES\n";
	return 0;
}