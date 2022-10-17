#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		std::vector<PII> A;
		FOR(i, n){
			int a, b;
			std::cin >> a >> b;
			A.push_back(MP(a, b));
		}
		bool good = false;
		FOR(i, n){
			good = true;
			FOR(j, n){
				if(std::abs(A[i].X-A[j].X) + std::abs(A[i].Y-A[j].Y) > k)
					good = false;
			}
			if(good) break;
		}
		if(good) std::cout << 1 << "\n";
		else std::cout << -1 << "\n";
	}

	return 0;
}