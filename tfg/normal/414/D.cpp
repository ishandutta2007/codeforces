#include <iostream>
#include <vector>
#include <cstdio>

typedef long long ll;

const int ms = 100100;

int freq[ms];
std::vector<int> a;
std::vector<int> edges[ms];

void dfs(int on, int par = -1, int h = 0) {
	freq[h]++;
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		dfs(to, on, h + 1);
	}
}

ll cost(int x) {
	long long ans = 1e10;
	long long cur_cost = 0;
	for(int i = 0; i < x; i++) {
		cur_cost += a[x - 1] - a[i];
	}
	ans = std::min(ans, cur_cost);
	for(int i = x; i < a.size(); i++) {
		cur_cost -= a[i - 1] - a[i - x];
		if(a[i] > a[i - 1]) {
			cur_cost += x - 1;
		}
		ans = std::min(cur_cost, ans);
	}
	return ans;
}

int main() {
	int n, k, p;
	std::cin >> n >> k >> p;
	k = std::min(n - 1, k);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i < n; i++) {
		while(freq[i]--) {
			a.push_back(i);
		}
	}
	int l = 1, r = k;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(cost(mid) <= p) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << std::endl;
}