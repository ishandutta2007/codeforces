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
	std::vector<PII> A;
	std::cin >> n;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	std::sort(A.begin(), A.end(), [](const PII &a, const PII &b){
		return (a.X-a.Y) > (b.X-b.Y); 
	});
	ll ans = 0;
	REP(i, 1, n+1){
		ans += 1ll*(A[i-1].X-A[i-1].Y)*i - A[i-1].X + 1ll*A[i-1].Y*n;
	}
	std::cout << ans;
	return 0;
}