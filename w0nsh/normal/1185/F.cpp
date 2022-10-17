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


const int INF = 2000000666;

int n, m;
VI A;
int zad[512];
PR<PII, PII> min[512];
PR<int, PII> cm[512];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n){
		int ile;
		std::cin >> ile;
		int mask = 0;
		FOR(j, ile){
			int a;
			std::cin >> a;
			a--;
			mask |= (1<<a);
		}
		A.push_back(mask);
	}
	FOR(i, 512) min[i] = MP(MP(INF, -1), MP(INF, -1));
	FOR(i, m){
		int ile = 0;
		int cena;
		std::cin >> cena;
		std::cin >> ile;
		int mask = 0;
		FOR(j, ile){
			int a;
			std::cin >> a;
			a--;
			mask |= (1<<a);
		}
		if(min[mask].X.X >= cena) min[mask].Y = min[mask].X, min[mask].X = MP(cena, i);
		else if(min[mask].Y.X > cena) min[mask].Y = MP(cena, i);
	}
	FOR(i, 512){
		int cnt = 0;
		TRAV(a, A) if(((a^i)&a) == 0) cnt++;
		zad[i] = cnt;
	}
	FOR(i, 512) cm[i] = MP(INF, MP(-1, -1));
	FOR(i, 512) REP(j, i, 512){
		if(i == j){
			if(min[i].X.X != INF && min[i].Y.X != INF)
				cm[i|j] = std::min(cm[i|j], MP(min[i].X.X+min[i].Y.X, MP(min[i].X.Y, min[i].Y.Y)));
		}
		else if(min[i].X.X != INF && min[j].X.X != INF){
			if(min[i].X.Y == min[j].Y.Y){
				if(min[i].Y.X != INF) cm[i|j] = std::min(cm[i|j], MP(min[i].Y.X+min[j].X.X, MP(min[i].Y.Y, min[j].X.Y)));
				if(min[j].Y.X != INF) cm[i|j] = std::min(cm[i|j], MP(min[i].X.X+min[j].Y.X, MP(min[i].X.Y, min[j].Y.Y)));
			}else{
				cm[i|j] = std::min(cm[i|j], MP(min[i].X.X+min[j].X.X, MP(min[i].X.Y, min[j].X.Y)));
			}
		}
		if(cm[i|j].Y.X == cm[i|j].Y.Y && cm[i|j].Y.X != -1){
			assert(false);
		}
	}
	FOR(i, 512) FOR(j, 512){
		if(((i^j)&i) == 0) cm[i] = std::min(cm[i], cm[j]);
	}
	int best = 0;
	FOR(i, 512) if(cm[i].X != INF) best = std::max(best, zad[i]);
	int bbb = -1;
	int bp = INF;
	FOR(i, 512) if(zad[i] == best && cm[i].X != INF){
		if(bbb == -1 || cm[i].X < bp){
			bbb = i;
			bp = cm[i].X;
		}
	}
	// std::cout << bbb << std::endl;
	// std::cout << cm[bbb].X << std::endl;
	std::cout << cm[bbb].Y.X+1 << " " << cm[bbb].Y.Y+1;
	return 0;
}