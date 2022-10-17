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

ll n, b;
std::vector<PR<ll, ll> > factors;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> b;
	ll cur = 2;
	ll have = b;
	while(cur*cur <= b && have > 1){
		int c = 0;
		while(have % cur == 0) have /= cur, c++;
		if(c > 0) factors.push_back(MP(cur, c));
		cur++;
	}
	if(have > 1) factors.push_back(MP(have, 1));
	ll min = 1000000000000000000ll;
	TRAV(fc, factors){
		ll cr = 0;
		ll fac = fc.X;
		ll pw = 1;
		while(true){
			cr += (n/fac);
			if(fac <= n/fc.X) fac *= fc.X, pw++;
			else break;
		}
		min = std::min(cr/fc.Y, min);
	}
	std::cout << min << "\n";
	return 0;
}