#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T = int>
class MCMF {
public:
	struct Edge {
		Edge(int a, T b, T c) : to(a), cap(b), cost(c) {}
		int to;
		T cap, cost;
	};

	MCMF(int size) {
		n = size;
		edges.resize(n);
		pot.assign(n, 0);
		dist.resize(n);
		visit.assign(n, false);
	}

	std::pair<T, T> mcmf(int src, int sink) {
		std::pair<T, T> ans(0, 0);
		if(!SPFA(src, sink)) return ans;
		fixPot();
		// can use dijkstra to speed up depending on the graph
		while(SPFA(src, sink)) {
			auto flow = augment(src, sink);
			ans.first += flow.first;
			ans.second += flow.first * flow.second;
			fixPot();
		}
		return ans;
	}

	void addEdge(int f, int to, T cap, T cost) {
		//std::cout << "adding edge (" << f << ", " << to << ", " << cap << ", " << cost << ")\n";
		edges[f].push_back(list.size());
		list.push_back(Edge(to, cap, cost));
		edges[to].push_back(list.size());
		list.push_back(Edge(f, 0, -cost));
	}
private:
	int n;
	std::vector<std::vector<int>> edges;
	std::vector<Edge> list;
	std::vector<int> from;
	std::vector<T> dist, pot;
	std::vector<bool> visit;

	/*bool dij(int src, int sink) {
		T INF = std::numeric_limits<T>::max();
		dist.assign(n, INF);
		from.assign(n, -1);
		visit.assign(n, false);
		dist[src] = 0;
		for(int i = 0; i < n; i++) {
			int best = -1;
			for(int j = 0; j < n; j++) {
				if(visit[j]) continue;
				if(best == -1 || dist[best] > dist[j]) best = j;
			}
			if(dist[best] >= INF) break;
			visit[best] = true;
			for(auto e : edges[best]) {
				auto ed = list[e];
				if(ed.cap == 0) continue;
				T toDist = dist[best] + ed.cost + pot[best] - pot[ed.to];
				assert(toDist >= dist[best]);
				if(toDist < dist[ed.to]) {
					dist[ed.to] = toDist;
					from[ed.to] = e;
				}
			}
		}
		return dist[sink] < INF;
	}*/

	std::pair<T, T> augment(int src, int sink) {
		std::pair<T, T> flow = {list[from[sink]].cap, 0};
		for(int v = sink; v != src; v = list[from[v]^1].to) {
			//std::cout << v << ' ';
			flow.first = std::min(flow.first, list[from[v]].cap);
			flow.second += list[from[v]].cost;
		}
		//std::cout << src << '\n';
		for(int v = sink; v != src; v = list[from[v]^1].to) {
			list[from[v]].cap -= flow.first;
			list[from[v]^1].cap += flow.first;
		}
		return flow;
	}

	std::queue<int> q;
	bool SPFA(int src, int sink) {
		T INF = std::numeric_limits<T>::max();
		dist.assign(n, INF);
		from.assign(n, -1);
		q.push(src);
		dist[src] = 0;
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			visit[on] = false;
			for(auto e : edges[on]) {
				auto ed = list[e];
				if(ed.cap == 0) continue;
				T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
				if(toDist < dist[ed.to]) {
					dist[ed.to] = toDist;
					from[ed.to] = e;
					if(!visit[ed.to]) {
						visit[ed.to] = true;
						q.push(ed.to);
					}
				}
			}
		}
		return dist[sink] < INF;
	}

	void fixPot() {
		T INF = std::numeric_limits<T>::max();
		for(int i = 0; i < n; i++) {
			if(dist[i] < INF) pot[i] += dist[i];
		}
	}
};

const int ms = 505;
int n;
int a[ms], cap[2][ms], size[2][ms], use[2][ms];
std::vector<int> edges[2][ms];
MCMF<int> graph(1);

void build(int on, int par, int w, int up) {
	if(cap[w][on] != ms) {
		if(up != -1) {
			size[w][up] += cap[w][on];
		}
		up = on;
	}
	use[w][on] = up;
	for(auto to : edges[w][on]) {
		if(to == par) continue;
		/* add edge
		if(w == 0) {
			graph.addEdge(2 * on + 1, 2 * to, ms, 0);
		} else {
			graph.addEdge(2 * n + 2 * to, 2 * n + 2 * on + 1, ms, 0);
		}*/
		build(to, on, w, up);
	}
	/* add cap
	if(w == 0) {
		graph.addEdge(2 * on, 2 * on + 1, cap[w][on], 0);
	} else {
		graph.addEdge(2 * n + 2 * on + 1, 2 * n + 2 * on, cap[w][on], 0);
	}*/
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x, y;
	std::cin >> n >> x >> y;
	graph = MCMF<int>(2 * n + 2);
	int src = 2 * n, sink = 2 * n + 1;
	x--;y--;
	//std::cout << "adding cost edges\n";
	for(int i = 0; i < n; i++) {
		cap[0][i] = cap[1][i] = ms;
		std::cin >> a[i];
		//graph.addEdge(2 * i + 1, 2 * n + 2 * i + 1, 1, -a[i]);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[0][u].push_back(v);
		edges[0][v].push_back(u);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[1][u].push_back(v);
		edges[1][v].push_back(u);
	}
	int q;
	std::cin >> q;
	while(q--) {
		int v, c;
		std::cin >> v >> c;
		v--;
		cap[0][v] = c;
	}
	std::cin >> q;
	while(q--) {
		int v, c;
		std::cin >> v >> c;
		v--;
		cap[1][v] = c;
	}
	//std::cout << "building 0\n";
	build(x, -1, 0, -1);
	//std::cout << "building 1\n";
	build(y, -1, 1, -1);
	if(cap[0][x] != cap[1][y]) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(size[0][i] > cap[0][i] || size[1][i] > cap[1][i]) {
			std::cout << "-1\n";
			return 0;
		}
		if(cap[0][i] != ms) {
			graph.addEdge(src, i, cap[0][i] - size[0][i], 0);
		}
		if(cap[1][i] != ms) {
			graph.addEdge(n + i, sink, cap[1][i] - size[1][i], 0);
		}
		//std::cout << "uses of " << i << " is (" << use[0][i] << ", " << use[1][i] << ")\n";
		graph.addEdge(use[0][i], n + use[1][i], 1, -a[i]);
	}
	auto ans = graph.mcmf(src, sink);
	if(ans.first != cap[0][x]) {
		std::cout << "-1\n";
	} else {
		std::cout << -ans.second << '\n';
	}
}