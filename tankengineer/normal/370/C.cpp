#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 100;
int n, m, cnt[M];

const int N = M * 2 + 2;
int source, target;

const int MM = N * N << 1;
int top, head[N], next[MM], to[MM], c[MM];

void addedge(int u, int v, int cap) {
	to[top] = v, next[top] = head[u], c[top] = cap, head[u] = top++;
}

int gap[N + 10], dis[N + 10];
bool over;

int go(int u, int delta) {
	if (u == target) {
		return delta;
	}
	
	int t = delta, tmp, mindis = target + 5;
	bool flag = false;

	for (int j = head[u]; ~j; j = next[j]) {
		int v = to[j];
		if (c[j] != 0) {
			mindis = min(mindis, dis[v]);
			if (dis[v] == dis[u] - 1) {
				flag = true;
				tmp = min(c[j], t);
				tmp = go(v, tmp);
				c[j] -= tmp;
				c[j ^ 1] += tmp;
				t -= tmp;
				if (over || t == 0) {
					return delta - t;
				}
			}
		}
	}
	
	if (!flag) {
		--gap[dis[u]];
		if (gap[dis[u]] == 0 && dis[u] > dis[target] && dis[u] < dis[source]) {
			over = true;
		}
		dis[u] = mindis + 1;
		++gap[dis[u]];
	}

	return delta - t;
}

void flow() {
	memset(gap, 0, sizeof(gap));
	memset(dis, 0, sizeof(dis));
	over = false;
	while (!over && dis[source] < target) {
		go(source, n);
	}
}

int main() {
	top = 0;
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		++cnt[--c];
	}
	source = m * 2;
	target = m * 2 + 1;	
	for (int i = 0; i < m; ++i) {
		addedge(source, i, cnt[i]);
		addedge(i, source, 0);
		addedge(i + m, target, cnt[i]);
		addedge(target, i + m, 0);
		for (int j = 0; j < m; ++j) {
			if (j == i) {
				continue;
			}
			addedge(i, j + m, n);
			addedge(j + m, i, 0);
		}
	}
	flow();
	vector<pair<int, int> > ans;
	for (int i = 0; i < m; ++i) {
		int u = i + m;
		for (int j = head[u]; ~j; j = next[j]) {
			int v = to[j];
			if (v >= 0 && v < m) {
				int cap = c[j];
				for (int k = 0; k < cap; ++k) {
					ans.push_back(make_pair(v + 1, u - m + 1));
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
		--cnt[ans[i].first - 1];
	}
	for (int j = 0; j < m; ++j) {
		while (cnt[j]) {
			printf("%d %d\n", j + 1, j + 1);
			cnt[j] -= 1;
		}
	}
	return 0;
}