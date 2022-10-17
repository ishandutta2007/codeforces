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

int tab[23][23];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int h, w;
		std::cin >> h >> w;
		FOR(i, h) FOR(j, w) tab[i][j] = 0;
		if(h % 2 == 1){
			for(int i = 0; i < h; i += 2) tab[i][0] = tab[i][w-1] = 1;
			for(int i = 1; i < w; ++i){
				if(tab[0][i-1] != 1 && (i+1 == w || tab[0][i+1] != 1)){
					tab[0][i] = tab[h-1][i] = 1;
				}
			}
		}else if(w % 2 == 1){
			for(int i = 0; i < w; i += 2) tab[0][i] = tab[h-1][i] = 1;
			for(int i = 1; i < h; ++i){
				if(tab[i-1][0] != 1 && (i+1 == h || tab[i+1][0] != 1)){
					tab[i][0] = tab[i][w-1] = 1;
				}
			}
		}else{
			for(int i = 0; i < w - 2; i += 2){
				tab[0][i] = tab[h-1][i] = 1;
			}
			tab[0][w-1] = tab[h-1][w-1] = 1;
			for(int i = 1; i < h; ++i){
				if(tab[i-1][0] != 1 && (i+1 == h || tab[i+1][0] != 1)){
					tab[i][0] = tab[i][w-1] = 1;
				}
			}

		}
		
		FOR(i, h){
			FOR(j, w){
				std::cout << tab[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	return 0;
}