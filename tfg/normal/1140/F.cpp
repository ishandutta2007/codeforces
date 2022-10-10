#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300000;

struct DSU {
	struct Node {
		int par, size[2];
	};

	DSU() {
		init();
	}

	void init() {
		for(int i = 0; i < 2*ms; i++) {
			Node cur;
			cur.par = -1;
			cur.size[0] = cur.size[1] = 0;
			cur.size[i/ms]++;
			ds[i] = cur;
			//std::cout << ds[i].par << ' ' << cur.par << std::endl;
		}
	}

	Node ds[2*ms];
	std::vector<std::pair<int, Node>> st;
	long long ans = 0;
	int getPar(int x) { return ds[x].par < 0 ? x : getPar(ds[x].par); }
	void makeUnion(int a, int b) {
		a = getPar(a);
		b = getPar(b);
		if(a == b) return;
		if(ds[a].par > ds[b].par) {
			std::swap(a, b);
		}
		st.emplace_back(b, ds[b]);
		st.emplace_back(a, ds[a]);
		for(int i = 0; i < 2; i++) {
			ans += (long long) ds[a].size[i] * ds[b].size[i^1];
			ds[a].size[i] += ds[b].size[i];
		}
		ds[a].par += ds[b].par;
		ds[b].par = a;
	}
	void rollback() {
		ds[st.back().first] = st.back().second;
		st.pop_back();
	}
};

DSU dsu;

std::vector<std::pair<int, int>> edges[2 * ms];
int n;

void add(std::pair<int, int> e, int l, int r) {
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) edges[l++].push_back(e);
		if(r & 1) edges[--r].push_back(e);
	}
}

long long ans[ms];
void dfs(int on) {
	//std::cout << "in " << on << std::endl;
	int ori = (int) dsu.st.size();
	long long cur = dsu.ans;
	for(auto e : edges[on]) {
		dsu.makeUnion(e.first, e.second);
	}
	if(on >= n) {
		ans[on-n] = dsu.ans;
	} else {
		dfs(on+on);
		dfs(on+on+1);
	}
	while((int) dsu.st.size() > ori) {
		dsu.rollback();
	}
	dsu.ans = cur;
	//std::cout << "out " << on << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	std::map<std::pair<int, int>, int> first;
	for(int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		std::pair<int, int> e(x-1, ms+y-1);
		if(first.count(e)) {
			add(e, first[e], i);
			first.erase(e);
		} else {
			first[e] = i;
		}
	}
	for(auto e : first) {
		add(e.first, e.second, n);
	}
	dfs(1);
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i+1 == n ? '\n' : ' ');
	}
}