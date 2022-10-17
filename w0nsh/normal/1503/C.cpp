#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	ll ans = 0;
	FOR(i, n){
		std::cin >> A[i].X >> A[i].Y;
		ans += A[i].Y;
	}
	std::sort(A.begin(), A.end());

	int upto = A[0].X + A[0].Y;
	REP(i, 1, n){
		ans += std::max(0, A[i].X - upto);
		upto = std::max(upto, A[i].X + A[i].Y);
	}

	std::cout << ans << "\n";

	return 0;
}