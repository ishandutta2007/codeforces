#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
#define int long long
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		VI A(n);
		FOR(i, n) std::cin >> A[i];

		auto op = [&](){
			int mx = -500000066600ll;
			FOR(i, n) mx = std::max(mx, A[i]);
			FOR(i, n) A[i] = mx-A[i];
		};

		op();
		k--;
		if(k%2 == 1) op();

		FOR(i, n) std::cout << A[i] << " ";
		std::cout << "\n";
	}

	return 0;
}