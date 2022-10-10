#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = (int)1e9 + 10;

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) {
		edges.resize(_n);
		this->n = _n;
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			T flow;
			pt = std::vector<int>(n, 0);
			while(flow = dfs(src, sink)) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap = 1) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};


int dist[100][100];

const int ms = 1010;

int spos[ms], satk[ms], sfuel[ms];
int bpos[ms], bdef[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(u == v) continue;
		dist[u][v] = dist[v][u] = 1;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int s, b;
	long long k, h;
	std::cin >> s >> b >> k >> h;
	Dinic<int> graph(s + b + 2);
	int src = s + b;
	int sink = src + 1;
	for(int i = 0; i < s; i++) {
		graph.addEdge(src, i);
		std::cin >> spos[i] >> satk[i] >> sfuel[i];
		spos[i]--;
	}
	for(int i = 0; i < b; i++) {
		graph.addEdge(s + i, sink);
		std::cin >> bpos[i] >> bdef[i];
		bpos[i]--;
	}
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < b; j++) {
			if(dist[spos[i]][bpos[j]] <= sfuel[i] && satk[i] >= bdef[j]) {
				graph.addEdge(i, s + j);
			}
		}
	}
	int maxFlow = graph.maxFlow(src, sink);
	long long ans = std::min(h * s, maxFlow * k);
	std::cout << ans << '\n';
}