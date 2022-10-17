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

const int INF = 1000000;
int n, m;
int tab[105][105];
int dist[105][105];
VI path;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) FOR(j, n){
		char xd;
		std::cin >> xd;
		if(xd == '1') tab[i][j] = true;
	}
	FOR(i, n) FOR(j, n) dist[i][j] = INF;
	FOR(i, n) FOR(j, n) if(tab[i][j]) dist[i][j] = 1;
	FOR(k, n) FOR(i, n) FOR(j, n){
		dist[i][j] = std::min(dist[i][j], dist[i][k]+ dist[k][j]);
	}
	FOR(i, n) dist[i][i] = INF;
	std::cin >> m;
	path.resize(m);
	FOR(i, m) std::cin >> path[i];
	FOR(i, m) path[i]--;
	VI ans;
	int pos = 0;
	while(pos < m){
		ans.push_back(pos);
		int best = pos+1;
		REP(i, 1, n+1){
			if(pos+i >= m) break;
			if(dist[path[pos]][path[pos+i]] == i) best = pos+i;
		}
		pos = best;
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << path[i]+1 << " ";
	return 0;
}