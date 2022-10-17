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

const int INF = 1000000006;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PR<PII, int> > A(n);
	FOR(i, n) std::cin >> A[i].X.X >> A[i].X.Y, A[i].Y = i;
	std::sort(A.begin(), A.end());
	VI range(n);
	VI dp(n);
	dp[n-1] = 1;
	range[n-1] = A[n-1].X.X;
	for(int i = n-2; i >= 0; --i){
		int have = 1;
		int cover = A[i].X.X;
		int upto = A[i].X.X+A[i].X.Y-1;
		while(cover < upto){
			auto nxt = std::upper_bound(A.begin(), A.end(), MP(MP(cover, INF), INF));
			if(nxt == A.end()) break;
			if(nxt->X.X > upto) break;
			cover = range[nxt-A.begin()];
			have += dp[nxt-A.begin()];
		}
		dp[i] = have;
		range[i] = cover;
	}
	VI ans(n);
	FOR(i, n) ans[A[i].Y] = dp[i];
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}