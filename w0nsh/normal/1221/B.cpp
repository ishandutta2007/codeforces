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

PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

	int n;
bool bounds(PII a){
	return a.X >= 0 && a.X < n && a.Y >= 0 && a.Y < n;
}

std::vector<PII> dirs = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

int tab[105][105];

void dfs(PII a){
	TRAV(d, dirs){
		auto c = a+d;
		if(!bounds(c) || tab[c.X][c.Y] != -1) continue;
		tab[c.X][c.Y] = 1-tab[a.X][a.Y];
		dfs(c);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) FOR(j, n) tab[i][j] = -1;
	tab[0][0] = 0;
	dfs(MP(0, 0));
	FOR(i, n){
		FOR(j, n){
			std::cout << (tab[i][j] ? 'W' : 'B');
		}
		std::cout << "\n";
	}
	
	return 0;
}