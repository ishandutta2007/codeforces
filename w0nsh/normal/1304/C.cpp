#include <bits/stdc++.h>
#define int long long
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

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		std::vector<PR<int, PII> > A;
		FOR(i, n){
			int when, l, h;
			std::cin >> when >> l >> h;
			A.push_back(MP(when, MP(l, h)));
		}
		bool bad = false;
		PII range = MP(m, m);
		int last = 0;
		TRAV(i, A){
			int passed = i.X-last;
			range = MP(range.X-passed, range.Y+passed);
			int mn = std::max(range.X, i.Y.X);
			int mx = std::min(range.Y, i.Y.Y);
			if(mn > mx){
				bad = true;
				break;
			}else{
				range = MP(mn, mx);
			}
			last = i.X;
		}
		if(bad) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}