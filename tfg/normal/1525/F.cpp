#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
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
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
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

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::pair<int, int>> edges(m);
	for(int i = 0; i < m; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		edges[i].first--;
		edges[i].second--;
	}
	std::vector<long long> x(k), y(k);
	for(int i = 0; i < k; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::vector<std::vector<int>> ans(k);
	std::vector<int> can(n, 3);
	// solve base
	auto getGraph = [&]() {
		Dinic<int> graph(n*2+2);
		int src = n*2;
		int sink = n*2+1;
		for(int i = 0; i < n; i++) {
			graph.addEdge(src, i, 1);
			graph.addEdge(n + i, sink, 1);
		}
		for(auto e : edges) {
			if((can[e.first] & 1) && (can[e.second] & 2)) {
				graph.addEdge(e.first, n + e.second, 2);
			}
		}
		return graph;
	};
	int haha = n - getGraph().maxFlow(n*2, n*2+1);
	int cur = haha;
	std::vector<int> sequence;
	while(haha <= k) {
		auto graph = getGraph();
		// O(N) times do this:
		// pass through O(N) vertices, do dinic so O(N^2.5), results in O(N^4.5) algorithm with good constant
		// or do faster idea, remove "go" thing from vertex that is cut in the left or "come" thing from vertex that is cut in the right
		graph.maxFlow(n*2, n*2+1);
		for(int i = 0; i < n; i++) {
			if(!graph.inCut(i)) {
				sequence.push_back((i+1));
				//std::cout << "removing go from " << i+1 << std::endl;
				can[i] &= 2;
				break;
			}
			if(graph.inCut(n+i)) {
				sequence.push_back(-(i+1));
				//std::cout << "removing come from " << i+1 << std::endl;
				can[i] &= 1;
				break;
			}
			assert(i != n-1);
		}
		haha++;
		assert(n - getGraph().maxFlow(n*2, n*2+1) == haha);
	}
	for(int i = 0; i < (int) sequence.size(); i++) {
		std::cerr << sequence[i] << (i + 1 == (int) sequence.size() ? '\n' : ' ');
	}
	// building answer
	long long best = -1;
	std::vector<std::vector<int>> bestAns(k);
	long long curCost = 0;
	int minID = 0;
	int pt = 0;
	for(int i = 0; i < k; i++) {
		long long restCost = 0;
		for(int j = i+1; j < k; j++) {
			restCost += x[j];
		}
		if(best < restCost + curCost) {
			best = restCost + curCost;
			bestAns = ans;
			for(int id = pt; id < (int) sequence.size(); id++) {
				bestAns[i].push_back(sequence[id]);
			}
		}
		if(y[i] < y[minID]) {
			minID = i;
		}
		curCost += x[i];
		while(cur <= i+1) {
			assert(pt < (int) sequence.size());
			ans[minID].push_back(sequence[pt++]);
			int use = (int) std::min(y[minID], x[minID]);
			x[minID] -= use;
			curCost -= use;
			cur++;
		}
	}
	if(best < curCost) {
		bestAns = ans;
		best = curCost;
	}
	ans = bestAns;
	// printing answer
	int sz = (int) ans.size();
	for(auto &v : ans) sz += (int) v.size();
	std::cout << sz << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		for(auto v : ans[i]) std::cout << v << ' ';
		std::cout << 0 << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}