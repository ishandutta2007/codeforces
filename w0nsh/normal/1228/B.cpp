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

int tab[3005][3005];

void fail(){
	std::cout << 0;
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int h, w;
	std::cin >> h >> w;
	FOR(i, h){
		int a;
		std::cin >> a;
		FOR(j, a){
			if(tab[i][j] == -1) fail();
			tab[i][j] = 1;
		}
		if(a != w){
			if(tab[i][a] == 1) fail();
			tab[i][a] = -1;
		}
	}
	FOR(j, w){
		int a;
		std::cin >> a;
		FOR(i, a){
			if(tab[i][j] == -1) fail();
			tab[i][j] = 1;
		}
		if(a != h){
			if(tab[a][j] == 1) fail();
			tab[a][j] = -1;
		}
	}
	int ans = 1;
	FOR(i, h) FOR(j, w) if(tab[i][j] == 0) ans = (ans+ans)%1000000007;
	std::cout << ans << "\n";
	return 0;
}