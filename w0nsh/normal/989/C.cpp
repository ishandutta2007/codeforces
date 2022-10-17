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

std::vector<PII> ile;
int tab[101][101];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 4){
		int a;
		std::cin >> a;
		ile.push_back(MP(a, i));
	}
	std::sort(ile.begin(), ile.end());
	if(ile[0].X != 1){
		FOR(i, 4){
			int pos = 0;
			while(ile[0].X != 1 && pos < 50){
				tab[i][pos] = ile[(pos+i%2)%2].Y;
				ile[(pos+i%2)%2].X--;
				pos++;
			}
			REP(j, pos, 50) tab[i][j] = ile[2].Y;
		}
		FOR(i, 50) tab[4][i] = ile[2].Y;
		ile[2].X--;
	}else{
		REP(j, 0, 5) FOR(i, 50) tab[j][i] = ile[0].Y;
	}
	VI todo;
	FOR(i, 3) FOR(j, ile[i+1].X) todo.push_back(ile[i+1].Y);
	int xpos = 6;
	int ypos = 0;
	REP(j, 5, 50) FOR(i, 50) tab[j][i] = ile[0].Y;
	while(!todo.empty()){
		if(ypos >= 50) xpos += 2, ypos = 0;
		tab[xpos][ypos] = todo.back();
		ypos += 2;
		todo.pop_back();
	}
	std::cout << "50 50\n";
	FOR(i, 50){
		FOR(j, 50) std::cout << (char)((int)'A'+tab[i][j]);
		std::cout << "\n";
	}
	return 0;
}