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

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];

		std::vector<PR<int, PII>> ops;
		for(int i = 0; i < n; i += 2){
			PII pr = MP(i, i+1);

			ops.push_back(MP(1, pr));
			ops.push_back(MP(2, pr));
			ops.push_back(MP(1, pr));
			ops.push_back(MP(1, pr));
			ops.push_back(MP(2, pr));
			ops.push_back(MP(1, pr));
		}

		std::cout << SZ(ops) << "\n";
		TRAV(p, ops){
			std::cout << p.X << " " << p.Y.X + 1 << " " << p.Y.Y + 1 << "\n";
		}
	}

	return 0;
}