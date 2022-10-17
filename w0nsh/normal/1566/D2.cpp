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

		std::map<int, VI> map;
		FOR(i, n*m){
			int a;
			std::cin >> a;
			map[a].push_back(i);
		}

		TRAV(pr, map){
			std::sort(pr.Y.begin(), pr.Y.end());
			std::reverse(pr.Y.begin(), pr.Y.end());
		}

		std::vector<VI> perm(n, std::vector<int>(m));

		int i = 0;
		int j = 0;
		TRAV(pr, map){
			auto vec = pr.Y;

			while(SZ(vec)){
				int need = m - j;
				VI moje;
				while(SZ(vec) && SZ(moje) < need){
					moje.push_back(vec.back());
					vec.pop_back();
				}
				std::reverse(moje.begin(), moje.end());
				FOR(k, SZ(moje)){
					perm[i][j++] = moje[k];
				}

				if(j == m){
					i++;
					j = 0;
				}
			}
		}

		ll ans = 0;
		FOR(kt, n){
			FOR(a, m){
				REP(b, a+1, m){
					if(perm[kt][a] < perm[kt][b]) ans++;
				}
			}
		}

		std::cout << ans << "\n";

	}

	return 0;
}