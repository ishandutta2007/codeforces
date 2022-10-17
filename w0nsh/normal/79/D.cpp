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

const int INF = 1000000666;

int n, k, l;
std::vector<VI> g;

int dist[20][20];

int distance[10005];
void bfs(int start){
	FOR(i, 10005) distance[i] = INF;
	distance[start] = 0;
	std::queue<int> que;
	que.push(start);
	while(SZ(que)){
		int v = que.front();
		que.pop();
		TRAV(ch, g[v]){
			if(distance[ch] == INF){
				distance[ch] = distance[v]+1;
				que.push(ch);
			}
		}
	}
}

ll dp[1<<20];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> l;
	std::vector<bool> need(n+1);
	FOR(i, k){
		int a;
		std::cin >> a;
		need[a] = true;
	}
	VI mv;
	FOR(i, l){
		int a;
		std::cin >> a;
		mv.push_back(a);
	}
	need.push_back(false);
	VI A(n+2);
	VI bad;
	REP(i, 1, n+2){
		if(need[i] != need[i-1]) A[i] = 1, bad.push_back(i);
	}
	g.resize(n+2);
	TRAV(jump, mv){
		REP(j, 1, n+2){
			if(j+jump > n+1) break;
			g[j].push_back(j+jump);
			g[j+jump].push_back(j);
		}
	}
	assert(SZ(bad) <= 20);
	FOR(i, SZ(bad)){
		bfs(bad[i]);
		REP(j, i+1, SZ(bad)) dist[i][j] = dist[j][i] = distance[bad[j]];
	}
	FOR(i, 1<<SZ(bad)) dp[i] = INF;
	dp[0] = 0;
	REP(mask, 1, 1<<SZ(bad)) if(__builtin_popcount(mask) % 2 == 0){
		int fs = -1;
		FOR(i, SZ(bad)){
			if(mask & (1<<i)){
				fs = i;
				break;
			}
		}
		FOR(i, SZ(bad)) if((mask & (1<<i)) && fs != i){
			dp[mask] = std::min(dp[mask ^ (1<<fs) ^ (1<<i)] + dist[fs][i], dp[mask]);
		}
	}
	std::cout << (dp[(1<<SZ(bad))-1] >= INF ? -1 : dp[(1<<SZ(bad))-1]) << "\n";
	
	return 0;
}