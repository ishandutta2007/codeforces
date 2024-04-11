#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300;
int n, m, u[MAXN], v[MAXN], E1[MAXN], top;

set <int> E[MAXN]; vector <int> EE[MAXN];
mt19937 RND(12345);

int main () {
	clock_t start = clock();
	n = read(), m = read(); int i, j;
	for (i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read();
		E[u[i]].insert(v[i]), E[v[i]].insert(u[i]);
	}
	if (E[1].find(n) != E[1].end()) { printf("1\n1 %d\n", n); return 0; }
	for (i = 2; i < n; i++) if (E[1].find(i) != E[1].end() && E[n].find(i) != E[n].end()) { printf("2\n1 %d %d\n", i, n); return 0; }
	for (i = 1; i <= m; i++) {
		if (u[i] == 1 || u[i] == n || v[i] == 1 || v[i] == n) continue;
		if (E[1].find(u[i]) != E[1].end() && E[n].find(v[i]) != E[n].end()) { printf("3\n1 %d %d %d\n", u[i], v[i], n); return 0; }
		if (E[1].find(v[i]) != E[1].end() && E[n].find(u[i]) != E[n].end()) { printf("3\n1 %d %d %d\n", v[i], u[i], n); return 0; }
	}
	for (i = 1; i <= m; i++) {
		if (u[i] == 1 || u[i] == n || v[i] == 1 || v[i] == n) continue;
		if (E[1].find(u[i]) != E[1].end() && E[1].find(v[i]) == E[1].end()) { printf("4\n1 %d %d 1 %d\n", u[i], v[i], n); return 0; }
		if (E[1].find(v[i]) != E[1].end() && E[1].find(u[i]) == E[1].end()) { printf("4\n1 %d %d 1 %d\n", v[i], u[i], n); return 0; }
		if (E[1].find(u[i]) != E[1].end() && E[1].find(v[i]) != E[1].end()) EE[u[i]].push_back(v[i]), EE[v[i]].push_back(u[i]);
	}
	for (i = 2; i <= n; i++) if (E[1].find(i) != E[1].end()) E1[++top] = i;
	if (top <= 2) { puts("-1"); return 0; }
	while (1) {
		if ((double(clock() - start)) / (double(CLOCKS_PER_SEC)) >= 1.900) { break; }
		int y = E1[RND() % top + 1]; if (EE[y].size() <= 1) continue;
		int x = EE[y][RND() % (int(EE[y].size()))], z = x;
		while (x == z) z = EE[y][RND() % (int(EE[y].size()))];
		if (E[x].find(z) == E[x].end()) { printf("5\n1 %d %d %d %d %d\n", x, y, z, x, n); return 0; }
	}
	puts("-1");
	return 0;
}