#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Info {
	Info(int a = 0, int b = 0, int c = (int) 1e9 + 1) : sum(a), h(b), lim(c) {}
	Info(Info info, int c) : sum(info.sum + (c >= info.lim ? 1 : -1)), h(info.h + 1), lim(info.lim) {}
	int sum, h, lim;
};
const int INF = 1e9;

template <class T, class C = std::less<T>>
struct MaxQueue {
	MaxQueue() {
		clear();
	}

	void clear() {
		id = 0;
		q.clear();
	}

	void push(T x) {
		std::pair<int, T> nxt(1, x);
		while((int) q.size() > id && cmp(q.back().second, x)) {
			nxt.first += q.back().first;
			q.pop_back();
		}
		q.push_back(nxt);
	}

	T qry() {
		return q[id].second;
	}

	void pop() {
		q[id].first--;
		if(q[id].first == 0) {
			id++;
		}
	}
private:
	std::vector<std::pair<int, T>> q;
	int id;
	C cmp;
};

struct Solver {
	Solver(int left, int right) : L(left), R(right) {}
	std::pair<int, int> operator()(const std::vector<std::vector<std::pair<int, Info>>> &a) {
		int n = (int) a.size();
		if(curSize.empty()) {
			curSize.assign(n, 0);
			perm.resize(n);
			for(int i = 0; i < n; i++) {
				perm[i] = i;
				for(auto p : a[i]) {
					curSize[i] = std::max(curSize[i], p.second.h);
				}
			}
			std::sort(perm.begin(), perm.end(), [&](int v1, int v2) { return curSize[v1] < curSize[v2]; });
		}
		cur.clear();
		MaxQueue<std::pair<int, int>> q;
		for(auto tree : perm) {
			//std::cout << "new subtree:\n";
			//for(auto p : a[tree]) std::cout << p.first << ", " << p.second.h << ", " << p.second.sum << '\n';
			if(tree == 0) {
				assert(cur.empty());
				cur.emplace_back(0, a[0][0].first);
				continue;
			}
			assert(!cur.empty());
			next.assign(curSize[tree] + 1, std::pair<int, int>(-INF, -INF));
			for(auto p : a[tree]) {
				next[p.second.h] = std::max(next[p.second.h], std::pair<int, int>(p.second.sum, p.first));
			}
			int ptl = std::min(R, (int) cur.size()) - 1;
			int ptr = ptl;
			q.clear();
			for(int h = 1; h <= curSize[tree]; h++) {
				while(ptl >= 0 && L <= h + ptl && h + ptl <= R) {
					q.push(cur[ptl--]);
				}
				while(ptr > ptl && !(L <= h + ptr && h + ptr <= R)) {
					q.pop();
					ptr--;
				}
				if(ptr == -1) break;
				if(ptl < ptr && q.qry().first + next[h].first >= 0) {
					//std::cout << "pairing " << q.qry().second << " with " << next[h].second << '\n';
					return std::pair<int, int>(q.qry().second, next[h].second);
				}
			}
			cur.resize(next.size(), std::pair<int, int>(-INF, -INF));
			for(int h = 1; h <= curSize[tree]; h++) {
				cur[h] = std::max(cur[h], next[h]);
			}
		}
		return std::pair<int, int>(-1, -1);
	}
	int L, R;
	std::vector<int> curSize, perm;
	std::vector<std::pair<int, int>> cur, next;
};

template<class Cost>
class CentroidDecomposition {
public:
	struct Edge {
		Edge(){}
		Edge(int v, Cost cost) : to(v), c(cost) {}
		int to;
		Cost c;
	};
	CentroidDecomposition(int _n) : n(_n), edges(_n), tree(_n), col(_n, -1), size(_n), pt(_n, 0) {}

	void addEdge(int u, int v, Cost c) {
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
		pt[u]++, pt[v]++;
	}

	int init() {
		int ans = init(0, 0);
		for(int i = 0; i < n; i++) {
			std::sort(edges[i].begin(), edges[i].end(), [&](Edge e1, Edge e2) { return col[e1.to] > col[e2.to]; });
		}
		return ans;
	}

	// to get only one centroid
	int getCentroid() {
		preDFS(0, -1);
		return getCen(0);
	}

	template<class Info>
	std::vector<std::vector<std::pair<int, Info>>> getInfo(int i, Info base) {
		std::vector<std::pair<int, Info>> a;
		std::vector<std::vector<std::pair<int, Info>>> ans(1, std::vector<std::pair<int, Info>>(1, std::pair<int, Info>(i, base)));
		for(int j = 0; j < pt[i]; j++) {
			a.clear();
			dfs(a, edges[i][j].to, i, col[i], Info(base, edges[i][j].c));
			ans.push_back(a);
		}
		return ans;
	}

	template<class Info>
	void dfs(std::vector<std::pair<int, Info>> &vec, int on, int par, int lim, Info h) {
		vec.emplace_back(on, h);
		for(auto e : edges[on]) {
			if(e.to == par) continue;
			if(col[e.to] <= lim) break;
			dfs(vec, e.to, on, lim, Info(h, e.c));
		}
	}

private:
	void preDFS(int on, int par) {
		size[on] = 1;
		for(int i = 0; i < pt[on]; i++) {
			int to = edges[on][i].to;
			if(col[to] != -1 || to == par) {
				std::swap(edges[on][i], edges[on][pt[on]-1]);
				if(col[to] != -1) {
					pt[on]--;
					i--;
				} else if(i+1 < pt[on]) {
					i--;
				}
				continue;
			}
			preDFS(to, on);
			size[on] += size[to];
			if(size[to] > size[edges[on][0].to]) {
				std::swap(edges[on][0], edges[on][i]);
			}
		}
	}

	int getCen(int on) {
		int sz = size[on];
		while(size[on] > 1 && 2 * size[edges[on][0].to] >= sz) on = edges[on][0].to;
		return on;
	}

	int init(int on, int c) {
		preDFS(on, -1);
		on = getCen(on);
		col[on] = c;
		for(auto e : edges[on]) {
			if(col[e.to] == -1) {
				tree[on].push_back(init(e.to, c+1));
			}
		}
		return on;
	}

	int n;
	std::vector<std::vector<Edge>> edges;
	std::vector<std::vector<int>> tree; // centroid tree edges
	std::vector<int> col, size, pt;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, L, R;
	std::cin >> n >> L >> R;
	CentroidDecomposition<int> tree(n);
	for(int i = 1; i < n; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		tree.addEdge(u, v, c);
	}
	tree.init();
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = i;
	}
	std::shuffle(a.begin(), a.end(), rng);
	int ans = -1;
	std::pair<int, int> wtf(-1, -1);
	for(auto on : a) {
		Solver solver(L, R);
		//std::cout << "centroid at " << on << "\n";
		if(1 || solver(tree.getInfo(on, Info(0, 0, ans+1))).first != -1) {
			int l = ans+1, r = (int) 1e9 + 1;
			while(l != r) {
				int mid = (l + r + 1) / 2;
				//std::cout << "mid is " << mid << '\n';
				if(solver(tree.getInfo(on, Info(0, 0, mid))).first != -1) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			auto kek = solver(tree.getInfo(on, Info(0, 0, l)));
			if(kek.first != -1) wtf = kek, ans = l;
		}
		//std::cout << "answer at " << ans << "!!!!!!\n";
	}
	std::cerr << ans << '\n';
	std::cout << wtf.first+1 << ' ' << wtf.second+1 << '\n';
}