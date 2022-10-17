#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	VI male;
	VI duze;
	FOR(i, n){
		if(A[i] <= m / 3){
			male.push_back(A[i]);
		}else{
			duze.push_back(A[i]);
		}
	}

	int D = SZ(duze);
	auto mat = Matching(SZ(male) + SZ(duze));

	if(SZ(duze) > SZ(male)){
		std::cout << -1 << "\n";
		return 0;
	}

	FOR(i, SZ(duze)){
		FOR(j, SZ(male)){
			if(duze[i] % male[j] != 0) continue;

			int co = 2 * duze[i] + male[j];
			if(co <= m){
				mat.add_edge(1 + i, 1 + D + j);
			}
		}
	}

	auto xd = mat.max_matching();
	if(xd < D){
		std::cout << -1 << "\n";
		return 0;
	}

	std::vector<PII> ans;
	std::vector<bool> dead(SZ(male));
	FOR(i, SZ(duze)){
		int kto = mat.match[1 + i] - D - 1;
		int r = male[kto];
		dead[kto] = true;
		ans.push_back(MP(2 * duze[i] + r, duze[i] + r));
	}

	FOR(i, SZ(male)){
		if(!dead[i]){
			ans.push_back(MP(3 * male[i], 2 * male[i]));
		}
	}

	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i.X << " " << i.Y << "\n";

	return 0;
}