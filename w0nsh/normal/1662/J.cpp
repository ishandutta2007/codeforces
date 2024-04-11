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

struct Dinic{
	struct Edge{
		int from, to, cap, flow;
		Edge(){}
		Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
	};
	static constexpr int INF = 1e9+7;
	std::vector<Edge> edges;
	std::vector<std::vector<int> > g;
	std::vector<bool> vis;
	std::vector<int> d, cur;
	Dinic(){}
	Dinic(int n){
		edges = std::vector<Edge>();
		vis = std::vector<bool>(n);
		d = cur = std::vector<int>(n);
		g = std::vector<std::vector<int> >(n);
	}
	void add_edge(int from, int to, int cap){
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		int t_m = (int)edges.size();
		g[from].push_back(t_m-2);
		g[to].push_back(t_m-1);
	}
	bool bfs(int s, int t){
		std::fill(vis.begin(), vis.end(), false);
		std::queue<int> q;
		q.push(s);
		d[s] = 0; vis[s] = 1;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i = 0; i < (int)g[x].size(); ++i){
				Edge &e = edges[g[x][i]];
				if(!vis[e.to] && e.cap > e.flow){
					vis[e.to] = 1;
					d[e.to] = d[x]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
 	int dfs(int x, int a, int s, int t){
		if(x == t || a == 0) return a;
		int flow  = 0, _f;
		for(int& i = cur[x]; i < (int)g[x].size(); ++i){
			Edge& e = edges[g[x][i]];
			if(d[x]+1 == d[e.to] && (_f = dfs(e.to, std::min(a, e.cap - e.flow), s, t)) > 0){
				e.flow += _f;
				edges[g[x][i]^1].flow -= _f;
				flow += _f;
				a -= _f;
				if(a == 0) break;
			}
		}
		return flow;
	}
	int max_flow(int s, int t){
		int flow = 0;
		while(bfs(s, t)){
			std::fill(cur.begin(), cur.end(), 0);
			flow += dfs(s, INF, s, t);
		}
		return flow;
	}
};

int tab[130][130];
int skill[130][130];
int where[130];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	FOR(i, n) FOR(j, n) std::cin >> tab[i][j], tab[i][j]--;
	FOR(i, n) FOR(j, n) std::cin >> skill[i][j];

	Dinic dinic(2 * n * n + 2);
	int sum = 0;
	const int S = 2 * n * n;
	const int T = S + 1;

	auto ind = [&](int i, int j, int kt){ return (i * n + j) * 2 + kt; };
	FOR(i, n) FOR(j, n){
		sum += n + skill[i][j];
		dinic.add_edge(S, ind(i, j, 0), n + skill[i][j]);
		dinic.add_edge(ind(i, j, 1), T, n + skill[i][j]);
	}
	auto add = [&](PII a, PII b, bool swap){
		if(swap) std::swap(a.X, a.Y), std::swap(b.X, b.Y);
		dinic.add_edge(ind(a.X, a.Y, 0), ind(b.X, b.Y, 0), Dinic::INF);
		dinic.add_edge(ind(a.X, a.Y, 1), ind(b.X, b.Y, 1), Dinic::INF);
		dinic.add_edge(ind(a.X, a.Y, 0), ind(b.X, b.Y, 1), Dinic::INF);
	};

	FOR(swp, 2){
		FOR(i, n){
			FOR(j, n) where[tab[i][j]] = j;
			FOR(j, n-1) add(MP(i, where[j]), MP(i, where[j+1]), swp);
		}
		FOR(i, n) REP(j, i+1, n){
			std::swap(tab[i][j], tab[j][i]);
			std::swap(skill[i][j], skill[j][i]);
		}
	}

	std::cout << sum - dinic.max_flow(S, T) - n * n << "\n";

	return 0;
}