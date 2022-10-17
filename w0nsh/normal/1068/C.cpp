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

int n, m;
bool tab[105][105];
int last[105];
std::vector<PII> pos[105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		b--;a--;
		tab[b][a] = true;
		tab[a][b] = true;
	}
	FOR(i, 105) last[i] = -1;
	int cur_x = 1;
	int cur_y = 1;
	int cur_yfree = 2;
	FOR(i, n){
		if(last[i] != -1) pos[i].push_back(MP(cur_x, last[i]));
		pos[i].push_back(MP(cur_x, cur_y));
		cur_x++;
		last[i] = cur_y;
		REP(j, i+1, n){
			if(tab[i][j]){
				pos[i].push_back(MP(cur_x, cur_y));
				last[i] = cur_y;
				if(last[j] != -1) pos[j].push_back(MP(cur_x, last[j]));
				pos[j].push_back(MP(cur_x, cur_yfree));
				last[j] = cur_yfree;
				cur_yfree++;
				cur_x++;
			}
		}
		cur_y = cur_yfree;
		cur_yfree++;
	}
	FOR(i, n){
		std::cout << SZ(pos[i]) << "\n";
		TRAV(j, pos[i]) std::cout << j.X << " " << j.Y << "\n";
	}
	return 0;
}