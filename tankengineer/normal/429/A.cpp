#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

const int N = 100005;
vector<int> edge[N];

int col[N], goal[N], dep[N];

vector<int> ans;

void go(int u, int fa, int odd, int even) {
	if (dep[u] % 2 == 0) {
		col[u] ^= even;
	} else {
		col[u] ^= odd;
	}
	if (col[u] != goal[u]) {
		ans.push_back(u);
		col[u] ^= 1;
		if (dep[u] % 2 == 0) {
			even ^= 1;
		} else {
			odd ^= 1;
		}
	}
	for (int j = 0; j < (int)edge[u].size(); ++j) {
		int v = edge[u][j];
		if (v == fa) {
			continue;
		}
		dep[v] = dep[u] + 1;
		go(v, u, odd, even);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", col + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", goal + i);
	}
	go(0, -1, 0, 0);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d\n", ans[i] + 1);
	}
	return 0;
}