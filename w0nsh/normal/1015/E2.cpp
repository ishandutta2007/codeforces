#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
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

int n, m;
bool T[1005][1005];
bool D[1005][1005];

struct Tree{
	int BOTTOM = 1024;
	bool tab[2048];

	Tree(){
		FOR(i, 2048) tab[i] = false;
	}
	
	bool get(int v){
		return tab[BOTTOM+v];
	}

	void set(int a, int b, int v=1, int lo=0, int hi=1023){
		if(a > b || tab[v]) return;
		if(a == lo && b == hi){
			tab[v] = true;
			return;
		}
		int mid = (lo+hi) >> 1;
		set(a, std::min(b, mid), v<<1, lo, mid);
		set(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}

	void fall(){
		REP(i, 2, 2048) if(tab[i>>1]) tab[i] = true;
	}
};

Tree trees[2][1001];
int dist[4][1001][1001];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n) FOR(j, m){
		char c;
		std::cin >> c;
		if(c == '*') T[i][j] = true;
	}
	FOR(i, n){
		dist[1][i][0] = (int)T[i][0] - 1;
		dist[3][i][m-1] = (int)T[i][m-1] - 1;
		REP(j, 1, m){
			dist[1][i][j] = dist[1][i][j-1] + 1;
			if(!T[i][j]) dist[1][i][j] = -1;
		}
		for(int j = m-2; j >= 0; --j){
			dist[3][i][j] = dist[3][i][j+1] + 1;
			if(!T[i][j]) dist[3][i][j] = -1;
		}
	}
	FOR(j, m){
		dist[0][0][j] = (int)T[0][j] - 1;
		dist[2][n-1][j] = (int)T[n-1][j] - 1;
		REP(i, 1, n){
			dist[0][i][j] = dist[0][i-1][j] + 1;
			if(!T[i][j]) dist[0][i][j] = -1;
		}
		for(int i = n-2; i >= 0; --i){
			dist[2][i][j] = dist[2][i+1][j] + 1;
			if(!T[i][j]) dist[2][i][j] = -1;
		}
	}
	std::vector<PR<PII, int> > mov;
	FOR(i, n) FOR(j, m){
		if(!T[i][j]) continue;
		int r = 2000000;
		FOR(l, 4) r = std::min(r, dist[l][i][j]);
		if(r > 0){
			mov.push_back({{i, j}, r});
			trees[0][i].set(j-r, j+r);
			trees[1][j].set(i-r, i+r);
		}
	}
	FOR(i, 2) FOR(j, 1000) trees[i][j].fall();
	FOR(i, n) FOR(j, m){
		D[i][j] = trees[0][i].get(j) || trees[1][j].get(i);
	}
	FOR(i, n) FOR(j, m) if(T[i][j] && !D[i][j]){
		std::cout << -1 << "\n";
		return 0;
	}
	std::cout << mov.size() << "\n";
	TRAV(pr, mov){
		std::cout << pr.X.X+1 << " " << pr.X.Y+1 << " " << pr.Y << "\n";
	}
	return 0;
}