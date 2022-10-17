#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int tab[305][305];
int ans[305][305];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		FOR(i, n){
			FOR(j, m){
				std::cin >> tab[i][j];
			}
		}
		
		bool good = true;
		FOR(i, n){
			FOR(j, m){
				ans[i][j] = 4;
				if(i == 0) ans[i][j]--;
				if(i == n-1) ans[i][j]--;
				if(j == 0) ans[i][j]--;
				if(j == m-1) ans[i][j]--;
				if(tab[i][j] > ans[i][j]) good = false;
			}
		}

		if(good){
			std::cout << "YES\n";
			FOR(i, n){
				FOR(j, m){
					std::cout << ans[i][j] << " ";
				}
				std::cout << "\n";
			}
		}else std::cout << "NO\n";

	}

	return 0;
}