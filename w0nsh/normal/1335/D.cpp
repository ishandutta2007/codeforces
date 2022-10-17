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

char tab[9][9];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		FOR(i, 9) FOR(j, 9) std::cin >> tab[i][j];
		auto change = [&](int i, int j){
			if(tab[i][j] == '3') tab[i][j] = '4';
			else tab[i][j] = '3';
		};
		std::vector<PII> p{{0,0}, {3, 1}, {6, 2}, {1, 3}, {4, 4}, {7, 5}, {2, 6}, {5, 7}, {8, 8}};
		TRAV(i, p) change(i.X, i.Y);
		FOR(i, 9){
			FOR(j, 9) std::cout << tab[i][j];
			std::cout << "\n";
		}
	}

	return 0;
}