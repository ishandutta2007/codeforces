#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 200005, M = N << 1;
int a[N];
int top, head[N], to[M], next[M];

void addedge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

int cnt, ord[N], pos[N], in[N], out[N], dep[N];

void dfs(int u, int fa) {
	in[u] = pos[u] = ++cnt;
	ord[cnt] = u;	
	for (int j = head[u]; ~j; j = next[j]) {
		int v = to[j];
		if (v != fa) {
			dep[v] = dep[u] * -1;
			dfs(v, u);
		}
	}
	out[u] = cnt;
}

inline int getID(int l, int r) {
	return l + r | l != r;
}

int tag[M];

void init(int l, int r) {
	if (l == r) {
		tag[getID(l, r)] = dep[ord[l]] * a[ord[l]];
		return;
	}
	int m = l + r >> 1;
	init(l, m);
	init(m + 1, r);
}

void insert(int l, int r, int a, int b, int val) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		tag[getID(l, r)] += val;
		return;
	}
	int m = l + r >> 1;
	insert(l, m, a, b, val);
	insert(m + 1, r, a, b, val);
}

int ask(int l, int r, int pos) {
	if (l == r) {
		return tag[getID(l, r)];
	}
	int m = l + r >> 1;
	if (pos <= m) {
		return tag[getID(l, r)] + ask(l, m, pos);
	} else {
		return tag[getID(l, r)] + ask(m + 1, r, pos);
	}
}

int main() {
	top = 0;
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		addedge(u, v);
		addedge(v, u);
	}
	cnt = -1;
	dep[0] = 1;
	dfs(0, -1);
	init(0, n - 1);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u, val;
			scanf("%d%d", &u, &val);
			--u;
			insert(0, n - 1, in[u], out[u], val * dep[u]);
		} else {
			int u;
			scanf("%d", &u);
			--u;
			printf("%d\n", ask(0, n - 1, pos[u]) * dep[u]);
		}
	}
	return 0;
}