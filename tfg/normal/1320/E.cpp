#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>
#include <cassert>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

class HLD {
public:
	void init(int n) {
		// this doesn't delete edges!
		sz.resize(n);
		in.resize(n);
		out.resize(n);
		rin.resize(n);
		p.resize(n);
		edges.resize(n);
		nxt.resize(n);
		h.resize(n);
	}

	void addEdge(int u, int v) {
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	void setRoot(int n) {
		t = 0;
		p[n] = n;
		h[n] = 0;
		prep(n, n);
		nxt[n] = n;
		hld(n);
	}

	int getLCA(int u, int v) {
		while(!inSubtree(nxt[u], v)) {
			u = p[nxt[u]];
		}
		while(!inSubtree(nxt[v], u)) {
			v = p[nxt[v]];
		}
		return in[u] < in[v] ? u : v;
	}

	bool inSubtree(int u, int v) {
		// is v in the subtree of u?
		return in[u] <= in[v] && in[v] < out[u];
	}

	std::vector<std::pair<int, int>> getPathtoAncestor(int u, int anc) {
		// returns ranges [l, r) that the path has
		std::vector<std::pair<int, int>> ans;
		//assert(inSubtree(anc, u));
		while(nxt[u] != nxt[anc]) {
			ans.emplace_back(in[nxt[u]], in[u] + 1);
			u = p[nxt[u]];
		}
		// this includes the ancestor!
		ans.emplace_back(in[anc], in[u] + 1);
		return ans;
	}
//private:
	std::vector<int> in, out, p, rin, sz, nxt, h;
	std::vector<std::vector<int>> edges;
	int t;

	void prep(int on, int par) {
		sz[on] = 1;
		p[on] = par;
		for(int i = 0; i < (int) edges[on].size(); i++) {
			int &u = edges[on][i];
			if(u == par) {
				std::swap(u, edges[on].back());
				edges[on].pop_back();
				i--;
			} else {
				h[u] = 1 + h[on];
				prep(u, on);
				sz[on] += sz[u];
				if(sz[u] > sz[edges[on][0]]) {
					std::swap(edges[on][0], u);
				}
			}
		}
	}

	void hld(int on) {
		in[on] = t++;
		rin[in[on]] = on;
		for(auto u : edges[on]) {
			nxt[u] = (u == edges[on][0] ? nxt[on] : u);
			hld(u);
		}
		out[on] = t;
	}
};


const int INF = 1e9;
const int ms = 200200;

HLD hld;

bool cmp(int u, int v) { return hld.in[u] < hld.in[v]; }

std::vector<int> virtualTree;
std::vector<std::pair<int, int>> edges[ms];
bool visit[ms];
int speed[ms];
int ans[ms];

typedef std::pair<int, int> ii;
typedef std::pair<ii, ii> i4;

void solve() {
	// reading input
	int virus, k;
	std::cin >> virus >> k;
	std::vector<int> special(k);
	std::priority_queue<i4, std::vector<i4>, std::greater<i4>> hp;
	for(int i = 0; i < virus; i++) {
		int city;
		std::cin >> city >> speed[i];
		city--;
		virtualTree.push_back(city);
		hp.push(i4(ii(0, i), ii(0, city)));
	}
	for(int i = 0; i < k; i++) {
		std::cin >> special[i];
		special[i]--;
		virtualTree.push_back(special[i]);
	}
	// building virtual tree
	std::sort(virtualTree.begin(), virtualTree.end(), cmp);
	for(int i = 0, n = (int) virtualTree.size(); i + 1 < n; i++) {
		virtualTree.push_back(hld.getLCA(virtualTree[i], virtualTree[i+1]));
	}
	std::sort(virtualTree.begin(), virtualTree.end(), cmp);
	virtualTree.resize(std::unique(virtualTree.begin(), virtualTree.end()) - virtualTree.begin());
	// build edges
	std::stack<int> st;
	for(auto v : virtualTree) {
		if(st.empty()) {
			st.push(v);
		} else {
			while(!st.empty() && !hld.inSubtree(st.top(), v)) st.pop();
			assert(!st.empty());
			edges[st.top()].emplace_back(v, hld.h[v] - hld.h[st.top()]);
			edges[v].emplace_back(st.top(), hld.h[v] - hld.h[st.top()]);
			st.push(v);
		}
	}
	// solve infection
	while(!hp.empty()) {
		int on = hp.top().second.second;
		int dist = hp.top().second.first;
		int curVirus = hp.top().first.second;
		hp.pop();
		if(visit[on]) continue;
		visit[on] = true;
		ans[on] = curVirus + 1;
		int s = speed[curVirus];
		for(auto e : edges[on]) {
			int toDist = e.second + dist;
			hp.push(i4(ii((toDist+s-1)/s, curVirus), ii(toDist, e.first)));
		}
	}
	// print answer
	for(int i = 0; i < k; i++) {
		std::cout << ans[special[i]] << (i + 1 == k ? '\n' : ' ');
	}
	// clean things
	for(auto v : virtualTree) {
		assert(visit[v]);
		visit[v] = false;
		edges[v].clear();
	}
	virtualTree.clear();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	hld.init(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		hld.addEdge(u, v);
	}
	hld.setRoot(0);
	int q;
	std::cin >> q;
	while(q--) {
		solve();
	}
}