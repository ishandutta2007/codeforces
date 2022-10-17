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

bool tab[1005][1005];
PII pos, dest;
std::vector<PII> rooks;
void move(int x, int y){
	x = std::max(1, x);
	y = std::max(1, y);
	x = std::min(999, x);
	y = std::min(999, y);
	std::cout << x << " " << y << std::endl;
	pos = MP(x, y);
	int a, b, c;
	std::cin >> a >> b >> c;
	if(a == -1 && b == -1 && c == -1) std::exit(0);
	a--;
	tab[rooks[a].X][rooks[a].Y] = false;
	rooks[a] = MP(b, c);
	tab[rooks[a].X][rooks[a].Y] = true;
}

std::vector<PII> cnt;
void destroy(){
	FOR(i, 4) cnt.push_back(MP(0, i));
	REP(i, 1, 500) REP(j, 1, 500){
		if(tab[i][j]) cnt[0].X++;
		if(tab[500+i][j]) cnt[1].X++;
		if(tab[500+i][500+j]) cnt[2].X++;
		if(tab[i][500+j]) cnt[3].X++;
	}
	std::sort(cnt.begin(), cnt.end());
	// TRAV(i, cnt) std::cout << i.X << " " << i.Y << std::endl;
	if(cnt[0].Y == 0) dest = MP(1, 1);
	else if(cnt[0].Y == 1) dest = MP(-1, 1);
	else if(cnt[0].Y == 2) dest = MP(-1, -1);
	else if(cnt[0].Y == 3) dest = MP(1, -1);
	// std::cout << dest.X << " " << dest.Y << std::endl;
	// std::exit(0);
	while(true){
		if(tab[pos.X+dest.X][pos.Y+dest.Y]) dest.Y = 0;
		move(pos.X+dest.X, pos.Y+dest.Y);
	}
}

void middle(){
	while(pos.X != 500 || pos.Y != 500){
		if(pos.X > 500) move(pos.X-1, pos.Y);
		if(pos.X < 500) move(pos.X+1, pos.Y);
		if(pos.Y < 500) move(pos.X, pos.Y+1);
		if(pos.Y > 500) move(pos.X, pos.Y-1);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> pos.X >> pos.Y;
	FOR(i, 666){
		int a, b;
		std::cin >> a >> b;
		tab[a][b] = true;
		rooks.push_back(MP(a, b));
	}
	middle();
	destroy();
	return 0;
}