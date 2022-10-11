#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 300200;

int dp[ms], step[ms], cur_step = 0;
std::vector<int> edges[ms], result[ms];
int verts[ms];
int deg[ms], size[ms];
int height[ms], color[ms], tot = 1, cstep[ms], cgot[ms], prv[ms];
ii cur_ans[ms];

bool cmp(int a, int b) {
	return deg[a] < deg[b];
}

void pre(int on, int par) {
	result[on].assign(edges[on].size(), 0);
	size[on] = 1;
	for(int i = 0; i < edges[on].size(); i++) {
		int to = edges[on][i];
		if(par == to) {
			std::swap(edges[on].back(), edges[on][i]);
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

void pre2(int on, int c = 0, int h = 0) {
	height[on] = h;
	color[on] = c;
	for(int i = 0; i < edges[on].size(); i++) {
		int to = edges[on][i];
		if(i == 0) {
			pre2(to, c, h + 1);
		} else {
			prv[tot] = on;
			pre2(to, tot++, 0);
		}
	}
}

int dfs(int on, int need) {
	if(deg[on] < need) {
		return 1;
	}
	if(cur_step == step[on]) {
		return dp[on];
	}
	step[on] = cur_step;
	int c = 0;
	for(int i = 0; i < edges[on].size(); i++) {
		int to = edges[on][i];
		if(deg[to] < need) {
			std::swap(edges[on].back(), edges[on][i]);
			edges[on].pop_back();
			i--;
			continue;
		}
		result[on][c++] = dfs(to, need);
	}
	int ans = 2;
	if(c >= need) {
		std::sort(result[on].begin(), result[on].begin() + c, std::greater<int>());
		ans = 1 + result[on][need - 1];
	}
	return dp[on] = ans;
}

long long up(int on) {
	if(on == -1) {
		return 0;
	}
	int ans = 0;
	if(cstep[color[on]] != cur_step) {
		cstep[color[on]] = cur_step;
		cgot[color[on]] = -1;
	}
	if(height[on] > cgot[color[on]]) {
		ans = height[on] - cgot[color[on]];
		cgot[color[on]] = height[on];
	}
	return ans + up(prv[color[on]]);
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		deg[u]++;
		deg[v]++;
		deg[i]--;
		verts[i] = i;
	}
	pre(0, -1);
	prv[0] = -1;
	pre2(0);
	long long ans = 0;
	std::sort(verts, verts + n, cmp);
	for(int i = 0; i < n; i++) {
		//std::cout << verts[i] << ", " << deg[verts[i]] << "\n";
	}
	for(int i = 1; i <= n; i++) {
		cur_step++;
		int got = 0;
		for(int j = n - 1; deg[verts[j]] >= i; j--) {
			//std::cout << "on " << verts[j] << ", need is " << i << " got " << dfs(verts[j], i) << "\n";
			cur_ans[got++] = ii(dfs(verts[j], i), verts[j]);
		}
		std::sort(cur_ans, cur_ans + got, std::greater<ii>());
		for(int i = 0; i < got; i++) {
			//std::cout << "on " << cur_ans[i].second << " got " << cur_ans[i].first << "\n";
			long long cur_got = up(cur_ans[i].second);
			//std::cout << "changed answer for " << cur_got << "\n";
			ans += cur_got * cur_ans[i].first;
			ans -= cur_got;
		}
		ans += n;
	}
	std::cout << ans << '\n';
}