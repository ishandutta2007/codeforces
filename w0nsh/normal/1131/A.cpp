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
	int w1, h1, w2, h2;
	std::cin >> w1  >> h1 >> w2 >> h2;
	ll fs = 2ll*(w1+2) + 2ll*h1 - w2;
	ll sec = 1ll*w2+2ll + 2ll*(h2-1);
	std::cout << fs+sec;
	return 0;
}