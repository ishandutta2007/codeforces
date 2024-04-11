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

char tab[105][1005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m , x, y;
		std::cin >> n >> m >> x >> y;
		FOR(i, n){
			FOR(j, m){
				std::cin >> tab[i][j];
			}
		}

		ll cost = 0;
		y = std::min(y, 2*x);
		FOR(i, n){
			FOR(j, m){
				if(tab[i][j] == '.'){
					if(j < m-1 && tab[i][j+1] == '.') cost += y, j++;
					else cost += x;
				}
			}
		}

		std::cout << cost << "\n";
	}

	return 0;
}