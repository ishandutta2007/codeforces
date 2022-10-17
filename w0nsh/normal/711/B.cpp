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

ll tab[505][505];

void fail(){
	std::cout << -1;
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	PII bd;
	FOR(i, n) FOR(j, n){
		std::cin >> tab[i][j];
		if(tab[i][j] == 0) bd = MP(i, j);
	}
	if(n == 1) std::cout << 2137 << "\n";
	else{
		ll sm = 0;
		int gdzie = 0;
		if(bd.X == 0) gdzie++;
		FOR(i, n){
			sm += tab[gdzie][i];
		}
		ll xd = 0;
		FOR(i, n){
			xd += tab[bd.X][i];
		}
		tab[bd.X][bd.Y] = sm-xd;
		if(tab[bd.X][bd.Y] < 1) fail();
		FOR(i, n){
			ll cur = 0;
			FOR(j, n){
				cur += tab[i][j];
			}
			if(cur != sm) fail();
		}
		FOR(i, n){
			ll cur = 0;
			FOR(j, n){
				cur += tab[j][i];
			}
			if(cur != sm) fail();
		}
		ll d1 = 0;
		ll d2 = 0;
		FOR(i, n) d1 += tab[i][i];
		FOR(i, n) d2 += tab[i][n-1-i];
		if(d1 != sm) fail();
		if(d2 != sm) fail();
		std::cout << tab[bd.X][bd.Y];
	}
	return 0;
}