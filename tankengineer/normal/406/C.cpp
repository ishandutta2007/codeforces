#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct ABC {
	int a, b, c;

	ABC(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<ABC> ans;

const int N = 100005, M = N << 1;
int n, m;
int head[N], to[M], next[M], top;
bool vis[N], used[M];

void addedge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

bool gos(int u, int fa) {
	vis[u] = true;
	int last = -1;
	for (int j = head[u]; ~j; j = next[j]) {
		int v = to[j];
		if (v == to[fa ^ 1]) {
			continue;
		}
		bool make = true;
		if (!vis[v]) {
			make = gos(v, j);
		} else {
			make = used[j >> 1];
		}
		if (!make) {
			if (last == -1) {
				last = j;
			} else {
				used[last >> 1] = used[j >> 1] = true;
				ans.push_back(ABC(to[last] + 1, u + 1, to[j] + 1));
				last = -1;
			}
		}
	}
	if (last == -1) {
		return false;
	} else {
		if (fa != -1) {
			used[last >> 1] = used[fa >> 1] = true;
			ans.push_back(ABC(to[fa ^ 1] + 1, u + 1, to[last] + 1));
		}
		return true;
	}
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		addedge(u, v);
		addedge(v, u);
	}
	bool over = false;
	for (int i = 0; i < n && !over; ++i) {
		if (!vis[i]) {
			over = gos(i, -1);
		}
	}
	if (!over) {
		for (int i = 0; i < m / 2; ++i) {
			printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
		}
	} else {
		puts("No solution");
	}
	return 0;
}