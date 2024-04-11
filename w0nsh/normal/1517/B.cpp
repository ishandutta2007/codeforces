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
		int n, m;
		std::cin >> n >> m;
		std::vector<VI> A(n, VI(m));
		std::vector<VI> ans(n, VI(m));
		std::vector<PII> vals;
		FOR(i, n){
			FOR(j, m){
				std::cin >> A[i][j];
				vals.push_back(MP(A[i][j], i));
			}
			std::sort(A[i].begin(), A[i].end());
		}
		std::sort(vals.begin(), vals.end());
		FOR(i, m){
			auto pos = vals[i].Y;
			assert(vals[i].X == A[pos][0]);
			FOR(j, n){
				if(j == pos){
					ans[j][i] = A[j][0];
					std::reverse(A[j].begin(), A[j].end());
					A[j].pop_back();
					std::reverse(A[j].begin(), A[j].end());
				}else{
					ans[j][i] = A[j].back();
					A[j].pop_back();
				}
			}
		}
		TRAV(i, ans){
			TRAV(j, i) std::cout << j << " ";
			std::cout << "\n";
		}
	}

	return 0;
}