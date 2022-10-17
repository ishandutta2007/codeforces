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
int h, w;

std::vector<PII> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
PII operator + (PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

bool bounds(PII a){
	if(a.X >= 0 && a.X < h && a.Y >= 0 && a.Y < w) return true;
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> h >> w;
	FOR(i, h){
		FOR(j, w){
			char x;
			std::cin >> x;
			if(x == '*') tab[i][j] = 1;
		}
	}
	std::vector<PII> gd;
	FOR(i, h){
		FOR(j, w){
			bool good = true;
			PII pos = MP(i, j);
			if(tab[pos.X][pos.Y] == 0) continue;
			TRAV(d, dirs){
				if(!bounds(pos+d)) good = false;
				else{
					PII xd = pos+d;
					if(tab[xd.X][xd.Y] == 0) good = false; 
				}
			}
			if(good) gd.push_back(pos);

		}
	}
	if(SZ(gd) != 1) std::cout << "NO\n";
	else{
		PII st = gd[0];
		tab[st.X][st.Y] = 0;
		TRAV(d, dirs){
			PII cur = st + d;
			while(bounds(cur) && tab[cur.X][cur.Y] == 1) tab[cur.X][cur.Y] = 0, cur = cur + d;
		}
		bool good = true;
		FOR(i, h) FOR(j, w){
			if(tab[i][j] == 1) good = false;
		}
		std::cout << (good ? "YES\n" : "NO\n");
	}
	return 0;
}