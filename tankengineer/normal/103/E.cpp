#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 305;
int n, val[N], vis[N], match[N], visCount;
vector<int> sale[N];

bool find(const int i) {
	if (vis[i] == visCount) {
		return false;
	}
	vis[i] = visCount;
	for (int j = 0; j < (int)sale[i].size(); ++j) {
		int v = sale[i][j];
		if (match[v] == -1 || find(match[v])) {
			match[v] = i;
			return true;
		}
	}
	return false;
}

const int M = N * N, INF = 1000000000;
int st, ed, top, head[N], next[M], v[M], c[M], dis[N], gap[N];
bool over;

void addedge(const int i, const int j, const int c1, const int c2 = 0) {
	v[top] = j; next[top] = head[i]; head[i] = top; c[top] = c1; ++top;
	v[top] = i; next[top] = head[j]; head[j] = top; c[top] = c2; ++top;
}

int flow(const int i, const int delta) {
	if (i == ed) {
		return delta;
	}

	int t = delta, tmp, mindis = n + 2 + 5;
	bool flag = false;

	for (int j = head[i]; j != -1; j = next[j]) {
		if (c[j]) {
			mindis = min(dis[v[j]], mindis);
			if (dis[v[j]] == dis[i] - 1) {
				flag = true;
				tmp = min(c[j], t);
				tmp = flow(v[j], tmp);
				t -= tmp;
				c[j] -= tmp;
				c[j ^ 1] += tmp;
				if (over || t == 0) {
					return delta - t;
				}
			}
		}
	}

	if (!flag) {
		--gap[dis[i]];
		if (gap[dis[i]] == 0 && dis[i] < dis[st] && dis[i] > dis[ed]) {
			over = true;
		}
		dis[i] = mindis + 1;
		++gap[dis[i]];
	}

	return delta - t;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			int t1;
			scanf("%d", &t1);
			--t1;
			sale[i].push_back(t1);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", val + i);
	}
	
	memset(vis, 0, sizeof(vis));
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; ++i) {
		++visCount;
		find(i);
	}

	st = n, ed = n + 1;
	memset(head, -1, sizeof(head));
	top = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (val[i] < 0) {
			addedge(st, i, -val[i]);
			sum += val[i];
		} else {
			addedge(i, ed, val[i]);
		}
		for (int j = 0; j < (int)sale[i].size(); ++j) {
			int v = match[sale[i][j]];
			if (v != i) {
				addedge(i, v, INF);
			}
		}
	}

	int ans = sum;
	over = false;
	while (!over && dis[st] < n + 2) {
		ans += flow(st, INF);
	}

	printf("%d\n", ans);
	return 0;
}