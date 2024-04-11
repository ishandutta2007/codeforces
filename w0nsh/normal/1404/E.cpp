#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


// 1-based indexing
struct Matching{
	static const int INF = 1000000666;
	int n;
	std::vector<std::vector<int> > g;
	std::vector<int> match, col, U, dist;
	Matching(){}
	Matching(int N){
		n = N;
		g = std::vector<std::vector<int> >(n+1);
		match = col = dist = std::vector<int>(n+1);
	}
	void add_edge(int a, int b){
		a++;b++;
		g[a].push_back(b); g[b].push_back(a);
	}
	void color(int v, int c){
		if((col[v] = c) == 1) U.push_back(v);
		for(auto ch : g[v]) if(!col[ch]) color(ch, (c == 1 ? 2 : 1));
	}
	bool bfs(){
		std::queue<int> que;
		for(auto u : U)
			if(!match[u]) dist[u] = 0, que.push(u);
			else dist[u] = INF;
		dist[0] = INF;
		while(!que.empty()){
			int u = que.front(); que.pop();
			if(dist[u] < dist[0]) for(auto v : g[u]) if(dist[match[v]] == INF)
				dist[match[v]] = dist[u] + 1, que.push(match[v]);
		}
		return dist[0] != INF;
	}
	bool dfs(int u){
		if(!u) return true;
		for(auto v : g[u]) if(dist[match[v]] == dist[u] + 1 && dfs(match[v]))
				return match[v] = u, match[u] = v;
		return dist[u] = INF, false;
	}
	int max_matching(){
		for(int i = 1; i <= n; ++i) if(!col[i]) color(i, 1);
		int ret = 0;
		while(bfs()) for(auto u : U) if(!match[u] && dfs(u)) ret++;
		return ret;
	}
};

int tab[205][205];

PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	int C = 0;
	FOR(i, n){
		FOR(j, m){
			char a;
			std::cin >> a;
			if(a == '#') tab[i][j] = 1, C++;
		}
	}

	Matching mat(n*m*4+5);

//	std::vector<VI> g(n*m*4);

	std::vector<PII> dirs{MP(0, 1), MP(1, 0), MP(0, -1), MP(-1, 0)};
	auto bounds = [&](PII a){
		return a.X >= 0 && a.X < n && a.Y >= 0 && a.Y < m;
	};

	auto ind =  [&](int x, int y){
		assert(x >= 0 && y >= 0);
		assert(x < 2*n);
		assert(y < 2*m);
		return x*2*m + y;
	};

	int cnt = 0;

	FOR(i, n){
		FOR(j, m){
			FOR(xd, 4){
				auto pos = MP(i, j);
				auto his = MP(i, j) + dirs[xd];
				auto his2 = MP(i, j) + dirs[(xd+1)%4];
				if(xd < 2 && bounds(his) && tab[pos.X][pos.Y] && tab[his.X][his.Y]){
//					std::cout << pos.X << ", " << pos.Y << "   " << his.X << "," << his.Y << std::endl;
					cnt++;
				}
				if(!bounds(his) || !bounds(his2)) continue;
				if(tab[pos.X][pos.Y] && tab[his.X][his.Y] && tab[his2.X][his2.Y]){
					int x1 = (pos.X+his.X);
					int y1 = (pos.Y+his.Y);
					int x2 = (pos.X+his2.X);
					int y2 = (pos.Y+his2.Y);
					int a = ind(x1, y1);
					int b = ind(x2, y2);
					mat.add_edge(a, b);
				}
			}
		}
	}

	int mtc = mat.max_matching();
/*	std::cerr << C << "\n";
	std::cerr << cnt << "\n";
	std::cerr << mtc << "\n";
*/
	std::cout << C-(cnt-mtc) << "\n";

	return 0;
}