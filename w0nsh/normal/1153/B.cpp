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

int tab[105][105];
int ret[105][105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, h;
	std::cin >> n >> m >> h;
	VI front(m), left(n);
	FOR(i, m) std::cin >> front[i];
	FOR(i, n) std::cin >> left[i];
	FOR(i, n) FOR(j, m){
		std::cin >> tab[i][j];
	}
	FOR(i, n){
		FOR(j, m){
			if(tab[i][j]) ret[i][j] = std::min(left[i], front[j]);
			std::cout << ret[i][j] << " " ;
		}
		std::cout << "\n";
	}
	return 0;
}