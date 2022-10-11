#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 1001000;

std::vector<int> edges[ms];
int step[ms], freq[ms], cur_step;
int size[ms];
int ans[ms];
int best;

void pre(int on, int par = -1) {
	size[on] = 1;
	for(int i = 0; i < edges[on].size(); i++) {
		int to = edges[on][i];
		if(to == par) {
			std::swap(edges[on][i], edges[on].back());
			edges[on].pop_back();
			i--;
			continue;
		}
		pre(to, on);
		size[on] += size[to];
		if(size[to] > size[edges[on][0]]) {
			std::swap(edges[on][0], edges[on][i]);
		}
	}
}

void reset() {
	cur_step++;
	best = 0;
	step[0] = cur_step;
	freq[0] = 0;
}

void add(int x) {
	if(step[x] != cur_step) {
		step[x] = cur_step;
		freq[x] = 0;
	}
	freq[x]++;
	//std::cout << "added to " << x << std::endl;
	if(freq[x] > freq[best] || (freq[x] == freq[best] && x < best)) {
		best = x;
		//std::cout << "new best is " << x << std::endl;
	}
}

void go(int on, int h) {
	add(h);
	for(auto to : edges[on]) {
		go(to, h + 1);
	}
}

void solve(int on, int h) {
	//std::cout << "solving for " << on << std::endl;
	if(edges[on].size() == 0) {
		//std::cout << "is leaf\n";
		add(h);
		return;
	}
	for(int i = 1; i < edges[on].size(); i++) {
		solve(edges[on][i], h + 1);
	}
	reset();
	solve(edges[on][0], h + 1);
	add(h);
	for(int i = 1; i < edges[on].size(); i++) {
		go(edges[on][i], h + 1);
	}
	//std::cout << "for " << on << ", best is " << best << " with " << freq[best] << std::endl;
	ans[on] = std::max(0, best - h);
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	pre(0);
	solve(0, 0);
	for(int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
}