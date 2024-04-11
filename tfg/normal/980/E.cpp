#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>

const int ms = 1001000;

std::vector<int> edges[ms];
int c = 0;
int up[ms], in[ms], out[ms];

void dfs(int on, int par = -1) {
	up[on] = par;
	in[on] = c++;
	for(auto to : edges[on]) {
		if(to != par) {
			dfs(to, on);
		}
	}
	out[on] = c;
}

struct BIT {
	void init(int n) {
		fw.assign(n + 1, 0);
	}

	void upd(int x, int v) {
		x++;
		for(; x < fw.size(); x += x & -x) {
			fw[x] += v;
		}
	}

	int qry(int x) {
		x++;
		int ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += fw[x];
		}
		return ans;
	}

	int qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}

	std::vector<int> fw;
};

int main() {
	int n, k;
	std::cin >> n >> k;
	std::set<int> ans;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(n);
	BIT fw;
	fw.init(n + 10);
	for(int i = 1; i < n; i++) {
		ans.insert(i);
		fw.upd(in[i], 1);
		fw.upd(out[i], -1);
	}
	for(int i = n - 1; i > 0; i--) {
		int dist = fw.qry(in[i]);
		if(ans.size() - dist < k) {
			continue;
		}
		int on = i;
		while(dist--) {
			ans.erase(on);
			fw.upd(in[on], -1);
			fw.upd(out[on], 1);
			on = up[on];
		}
	}
	std::vector<int> hmm;
	for(auto v : ans) hmm.push_back(v);
	for(int i = 0; i < k; i++) {
		printf("%d%c", hmm[i], i + 1 == k ? '\n' : ' ');
	}
}