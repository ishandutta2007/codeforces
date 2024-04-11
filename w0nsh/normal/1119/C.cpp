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

int tab[505][505];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	FOR(i, n) FOR(j, m) std::cin >> tab[i][j];
	FOR(i, n) FOR(j, m){
		int a;
		std::cin >> a;
		tab[i][j] = (int)(tab[i][j] != a);
	}
	FOR(i, n-1){
		int last = -1;
		FOR(j, m){
			if(tab[i][j] == 0) continue;
			if(last == -1){
				last = j;
			}else{
				tab[i+1][last] = !tab[i+1][last];
				tab[i+1][j] = !tab[i+1][j];
				last = -1;
			}
		}
		if(last != -1){
			std::cout << "No\n";
			return 0;
		}
	}
	FOR(i, m) if(tab[n-1][i] == 1){
		std::cout << "No\n";
		return 0;
	}
	std::cout << "Yes\n";
	return 0;
}