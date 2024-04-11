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

ll a, b, x, y;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> a >> b >> x >> y;
	ll gcd = std::__gcd(x, y);
	x = x/gcd;
	y = y/gcd;
	ll fs = a/x;
	ll sc = b/y;
	std::cout << std::min(fs,sc) << "\n";
	return 0;
}