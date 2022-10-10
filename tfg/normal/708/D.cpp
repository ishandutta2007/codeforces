#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
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
		while(dij(src, sink)) {
			auto flow = augment(src, sink);
			if(flow.second >= 0) break;
			ans.first += flow.first;
			ans.second += flow.first * flow.second;
			fixPot();
		}
		return ans;
	}

	void addEdge(int frm, int to, T cap, T cost) {
		if(cap == 0) return;
		edges[frm].push_back(list.size());
		list.push_back(Edge(to, cap, cost));
		edges[to].push_back(list.size());
		list.push_back(Edge(frm, 0, -cost));
	}
private:
	int n;
	std::vector<std::vector<int>> edges;
	std::vector<Edge> list;
	std::vector<int> from;
	std::vector<T> dist, pot;
	std::vector<bool> visit;

	bool dij(int src, int sink) {
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
	}

	std::pair<T, T> augment(int src, int sink) {
		std::pair<T, T> flow = {list[from[sink]].cap, 0};
		for(int v = sink; v != src; v = list[from[v]^1].to) {
			flow.first = std::min(flow.first, list[from[v]].cap);
			flow.second += list[from[v]].cost;
		}
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



int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	MCMF<long long> graph(n + 2);
	int src = n, sink = n + 1;
	std::vector<int> deg(n, 0);
	long long ans = 0;
	const int INF = 1e9;
	while(m--) {
		int u, v, c, f;
		std::cin >> u >> v >> c >> f;
		u--;v--;
		deg[u] -= f;
		deg[v] += f;
		if(c <= f) {
			ans += f - c;
			graph.addEdge(v, u, c, 1);
			graph.addEdge(v, u, f-c, 0);
			graph.addEdge(u, v, INF, 2);
		} else {
			graph.addEdge(v, u, f, 1);
			graph.addEdge(u, v, c-f, 1);
			graph.addEdge(u, v, INF, 2);
		}
	}
	for(int i = 1; i < n-1; i++) {
		ans += abs(deg[i]) * (long long) INF;
		if(deg[i] > 0) graph.addEdge(src, i, deg[i], -INF);
		else graph.addEdge(i, sink, -deg[i], -INF);
	}
	graph.addEdge(src, 0, INF, 0);
	graph.addEdge(src, n-1, INF, 0);
	graph.addEdge(0, sink, INF, 0);
	graph.addEdge(n-1, sink, INF, 0);
	ans += graph.mcmf(src, sink).second;
	//graph.print();
	std::cout << ans << '\n';
}