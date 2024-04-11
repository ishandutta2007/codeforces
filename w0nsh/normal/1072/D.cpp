#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, k;
int tab[2005][2005];
int mina[2005][2005];
std::set<PII> que[2];

void bfs(){
	que[0].insert({1, 1});
	FOR(i, 2*n-1){
		int min = 666;
		while(!que[0].empty()){
			auto cur = *que[0].begin();
			que[0].erase(que[0].begin());
			if(cur.X > n || cur.Y > n) continue;
			if(tab[cur.X][cur.Y] < min){
				que[1].clear();
				que[1].insert({cur.X, cur.Y+1});
				que[1].insert({cur.X+1, cur.Y});
				min = tab[cur.X][cur.Y];
			}else if(tab[cur.X][cur.Y] == min){
				que[1].insert({cur.X, cur.Y+1});
				que[1].insert({cur.X+1, cur.Y});
			}
		}
		std::swap(que[0], que[1]);
		std::cout << (char)('a' + min);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	REP(i, 1, n+1) REP(j, 1, n+1){
		char ch;
		std::cin >> ch;
		tab[i][j] = ch-'a';
	}
	FOR(i, n+1) mina[i][0] = mina[0][i] = 1000000000;
	mina[1][0] = 0;
	REP(i, 1, n+1) REP(j, 1, n+1){
		mina[i][j] = std::min(mina[i-1][j], mina[i][j-1]);
		if(tab[i][j] != 0) mina[i][j]++;
		if(mina[i][j] <= k) tab[i][j] = 0;
	}
	bfs();
	return 0;
}