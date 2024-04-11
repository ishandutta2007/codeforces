// Created time: 2022/6/19 9:48:36
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int n, m, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dis[MAXN + 5], res[MAXN + 5], now[MAXN + 5];
vector<int> vec[MAXN + 5];
int main() {
	scanf("%d", &n);
	memset(dis, -1, sizeof(dis));
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	scanf("%d", &m); queue<int> q;
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), dis[x] = 0, q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (!~dis[y]) dis[y] = dis[x] + 1, q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) vec[dis[i]].push_back(i);
	for (int i = n; i; i--) {
		for (int x : vec[i]) if (now[x] < i) now[x] = i, q.push(x);
		while (!q.empty()) {
			int x = q.front(); q.pop(); if (!now[x]) continue;
			res[x] = max(res[x], i);
			for (int e = hd[x]; e; e = nxt[e]) {
				int y = to[e];
				if (now[y] < now[x] - 1) {
					now[y] = now[x] - 1;
					q.push(y);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	return 0;
}