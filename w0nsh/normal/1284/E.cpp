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
typedef long double ld;

const ld PI = std::acos((ld)-1);

ll c3(int a){
	return 1ll*a*(a-1)*(a-2)/6;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	ll ans = 0;
	FOR(s, n){
		std::vector<ld> xd;
		FOR(i, n) if(i != s) xd.push_back(std::atan2((ld)(A[i].Y-A[s].Y), (ld)(A[i].X-A[s].X)));
		std::sort(xd.begin(), xd.end());
//		TRAV(i, xd) std::cout << i << "\n";
		FOR(i, n-1) xd.push_back(xd[i]+PI*2);
		int p1 = 0;
		int p2 = std::lower_bound(xd.begin(), xd.end(), xd[p1]+PI) - xd.begin();
		while(p1 < n-1){
			int ile = p2-p1-1;
			ans += c3(ile);
			p1++;
			while(p2 < 2*(n-1) && xd[p2] <= xd[p1]+PI) p2++;
		}
	}
	ll all = 1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/24ll;
	std::cout << all-ans << "\n";
	return 0;
}