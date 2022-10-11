#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>

class Dinic {
public:
	struct Edge {
		Edge(int a, int b){to = a;cap = b;}
		int to, cap;
	};
	
	Dinic(int n) {
		edges.resize(n);
		this->n = n;
	}

	int maxFlow(int src, int sink) {
		int ans = 0;
		while(bfs(src, sink)) {
			int flow;
			pt = std::vector<int>(n, 0);
			while(flow = dfs(src, sink)) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, int cap = 1) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}
//private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	int dfs(int on, int sink, int flow = 1e9) {
		if(flow == 0) {
			return 0;
		} else if(on == sink) {
			return flow;
		}
		for(; pt[on] < edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			int got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h.assign(n, n + 2);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a:edges[on]) {
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

typedef std::pair<int, int> ii;

const int ms = 2020 * 2;

int deg[ms];
ii edges[ms];
bool cut[ms];

int main() {
	int n1, n2, m;
	std::cin >> n1 >> n2 >> m;
	Dinic graph(n1 + n2 + 2);
	int src = n1 + n2;
	int sink = src + 1;
	for(int i = 0; i < m; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		edges[i].first--;
		edges[i].second--;
		edges[i].second += n1;
		graph.addEdge(edges[i].first, edges[i].second);
	}
	int lim = m;
	for(int i = 0; i < n1 + n2; i++) {
		lim = std::min((int)graph.edges[i].size(), lim);
		if(i < n1) {
			graph.addEdge(src, i, 0);
		} else {
			graph.addEdge(i, sink, 0);
		}
	}
	for(int i = 0; i <= lim; i++) {
		graph.maxFlow(src, sink);
		for(int j = 0; j < n1 + n2; j++) {
			deg[j] = 0;
		}
		std::vector<int> ans;
		for(int j = 0; j < m; j++) {
			cut[j] = graph.list[2 * j].cap == 0;
			if(cut[j]) {
				ans.push_back(j + 1);
				deg[edges[j].first]++;
				deg[edges[j].second]++;
			}
		}
		for(int j = 0; j < m; j++) {
			if(!cut[j] && std::min(deg[edges[j].first], deg[edges[j].second]) < i) {
				ans.push_back(j + 1);
				deg[edges[j].first]++;
				deg[edges[j].second]++;
			}
		}
		std::cout << ans.size();
		for(auto v : ans) {
			printf(" %d", v);
		}
		std::cout << '\n';
		for(int j = 0; j < n1 + n2; j++) {
			graph.list[2 * m + 2 * j].cap++;
		}
	}
}