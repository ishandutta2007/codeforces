#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::vector<bool> tab[50005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		VI col(m);
		VI row(n);
		FOR(i, n) tab[i].clear();
		FOR(i, n){
			FOR(j, m){
				char a;
				std::cin >> a;
				if(a == '.') col[j]++, row[i]++;
				if(a == '.') tab[i].push_back(true);
				else tab[i].push_back(false);
			}
		}
		int best = 1000000666;
		FOR(i, n){
			FOR(j, m){
				best = std::min(best, col[j]+row[i]-(tab[i][j] ? 1 : 0));
			}
		}
		std::cout << best << "\n";
	}
	return 0;
}