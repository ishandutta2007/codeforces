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

void solve(){
	int n, k;
	std::cin >> n >> k;
	std::vector<PII> A(n);
	ll ans = 0;
	FOR(i, n){
		std::cin >> A[i].Y;
		ans += A[i].Y;
		A[i].X = -A[i].Y - i;
	}
	std::sort(A.begin(), A.end());
	FOR(x, k){
		ans += n - 1 + A[x].X;
		ans -= x;
	}
	
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}