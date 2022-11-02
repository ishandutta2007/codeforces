#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2 * 100000 + 5;
int n, a[N];

const int M = N * 4;

int top, head[N], next[M], to[M], l[M], dis[N];
bool inque[N];

void addedge(int u, int v, int c) {
	to[top] = v, next[top] = head[u], l[top] = c, head[u] = top++;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
	}
	int mins = 0, maxs = 0;
	for (int i = 0; i < n; ++i) {
		int bmin = mins / 5, bmax = maxs / 5;
		if (a[i] != -1) {
			if (a[i] < bmin || a[i] > bmax) {
				printf("-1\n");
				return 0;
			}
			mins = max(a[i] * 5, mins);
			maxs = min(a[i] * 5 + 4, maxs);
		}
		if (i != n - 1) {
			++mins;
			if (maxs % 5 > 0) {
				maxs = (maxs / 5 + 1) * 5;
			} else {
				++maxs;
			}
		}
	}
	int ans = maxs / 5 + (int)(maxs % 5 > 0);
	if (ans < a[n - 1] + 1) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
	a[n - 1] = ans - 1;
	for (int i = 0; i < n; ++i) {
		++a[i];
	}
	top = 0;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= ans; ++i) {
		addedge(i, i - 1, -5); //s[i - 1] - s[i] >= -5
	}
	for (int i = 0; i < ans; ++i) {
		addedge(i, i + 1, 2); // s[i + 1] - s[i] >= 2
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			addedge(0, a[i], i + 1); // s[a[i]] - s[0] >= i + 1
			addedge(a[i] - 1, 0, -i); // s[0] - s[a[i] - 1] >= -i
		}
	}
	for (int i = 0; i <= ans; ++i) {
		dis[i] = 0;
	}
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int u = q.front();
		inque[u] = false;
		q.pop();
		for (int j = head[u]; ~j; j = next[j]) {
			int v = to[j];
			if (dis[v] < dis[u] + l[j]) {
				dis[v] = dis[u] + l[j];
				if (!inque[v]) {
					q.push(v);
					inque[v] = true;
				}
			}
		}
	}
	vector<int> anst;
	for (int i = 0; i < ans; ++i) {
		for (int j = 0; j < dis[i + 1] - dis[i]; ++j) {
			anst.push_back(i + 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", anst[i], " \n"[i == n - 1]);
	}
	return 0;
}