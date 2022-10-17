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

int tab[50004][5];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;

		FOR(i, n){
			FOR(j, 5) std::cin >> tab[i][j];	
		}

		int best = 0;
		REP(i, 1, n){
			int ile = 0;
			FOR(j, 5) if(tab[best][j] < tab[i][j]) ile++;
			if(ile <= 2){
				best = i;
			}
		}

		bool good = true;
		FOR(i, n) if(i != best){
			int ile = 0;
			FOR(j, 5) if(tab[best][j] < tab[i][j]) ile++;
			if(ile <= 2) good = false;
		}

		if(good) std::cout << best +1 << "\n";
		else std::cout << -1 << "\n";
	}

	return 0;
}