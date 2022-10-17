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
	int n;
	std::cin >> n;
	int la = 0, lb = 0;
	int ans = 1;
	// int biglast = 0;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		int mx = std::max(la, lb);
		int mn = std::min(a, b);
		int xd = mn-mx+1;
		if(la == lb) xd--;
		ans += std::max(0, xd);
		la = a;
		lb = b;
	}
	std::cout << ans;
	return 0;
}