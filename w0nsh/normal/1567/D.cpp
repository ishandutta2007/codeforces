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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int s, n;
		std::cin >> s >> n;

		std::vector<int> A(n);
		int pot = 1000000000;
		int kt = 0;
		bool good = false;
		while(pot){
			int ile = s / pot;
			int w = ile;
			while(w >= 0){
				int zost = s - pot * w;
				if (n - kt - w <= zost) {
					break;
				}
				w--;
			}
			assert(w >= 0);

			FOR(j, w){
				A[kt++] += pot;
				s -= pot;
				if(kt == n){
					good = true;
					break;
				}
			}

			if (good){
				A[0] += s;
				break;
			}

			pot /= 10;
		}

		FOR(j, n) std::cout << A[j] << " ";
		std::cout << std::endl;
	}

	return 0;
}