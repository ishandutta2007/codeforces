#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 400400;
int n, m, K;
vector <int> E[MAXN];

bool fail = 0;
void add(int p1, int val1, bool c1, int p2, int val2, bool c2) {
	if (val1 == K || val1 == 0) {
		if (val1 == K && c1) return;
		if (val1 == 0 && !c1) return;
		p1 = p2, val1 = val2, c1 = c2;
	}
	if (val2 == K || val2 == 0) {
		if (val2 == K && c2) return;
		if (val2 == 0 && !c2) return;
		p2 = p1, val2 = val1, c2 = c1;
	}
	if (val1 == 0 || val1 == K) { fail = 1; return; }
	// printf("add %d %d %d %d\n", p1 + (val1 - 1) * n, c1, p2 + (val2 - 1) * n, c2);
	// printf("add %d %d\n", p1 + (val1 - 1) * n + (!c1) * n * (K - 1), p2 + (val2 - 1) * n + c2 * n * (K - 1));
	// printf("add %d %d\n", p2 + (val2 - 1) * n + (!c2) * n * (K - 1), p1 + (val1 - 1) * n + c1 * n * (K - 1));
	E[p1 + (val1 - 1) * n + (!c1) * n * (K - 1)].push_back(p2 + (val2 - 1) * n + c2 * n * (K - 1));
	E[p2 + (val2 - 1) * n + (!c2) * n * (K - 1)].push_back(p1 + (val1 - 1) * n + c1 * n * (K - 1));
}

#define top (2 * n * (K - 1))
int dfn[MAXN], low[MAXN], col[MAXN], cc, cnt;
vector <int> stk; bool vis[MAXN];

void tarjan(int x) {
	dfn[x] = low[x] = ++cnt; vis[x] = 1, stk.push_back(x);
	for (auto i: E[x]) {
		if (!dfn[i]) tarjan(i), low[x] = min(low[x], low[i]);
		else if (vis[i]) low[x] = min(low[x], dfn[i]);
	}
	if (low[x] == dfn[x]) {
		col[x] = ++cc;
		while (stk.back() != x) col[stk.back()] = cc, vis[stk.back()] = 0, stk.pop_back();
		vis[x] = 0, stk.pop_back();
	}
}
void clear() {
	fail = 0;
	for (int i = 1; i <= top; i++) E[i].clear(), dfn[i] = low[i] = col[i] = 0, vis[i] = 0;
	cc = cnt = 0; stk.clear();
}

int main() {
	int T = read(); while (T--) {
		fail = 0;
		n = read(), m = read(), K = read(); int i, j;
		for (i = 1; i <= n; i++) for (j = 1; j < K; j++) {
			add(i, j, 0, i, j + 1, 1);
			if (i < n) add(i, j, 1, i + 1, j, 0);
		}
		while (m--) {
			int op = read();
			if (op == 1) {
				int i = read(), x = read();
				add(i, x - 1, 1, i, x, 0);
			}
			if (op == 2) {
				int i = read(), j = read(), x = read();
				for (int p = 1; p <= K; p++) for (int q = 1; q <= K; q++) if (p + q > x) {
					add(i, p - 1, 1, j, q - 1, 1);
					break;
				}
			}
			if (op == 3) {
				int i = read(), j = read(), x = read();
				for (int p = K; p >= 1; p--) for (int q = K; q >= 1; q--) if (p + q < x) {
					add(i, p, 0, j, q, 0);
					break;
				}
			}
		}
		if (fail) { puts("-1"); clear(); continue; }
		for (i = 1; i <= top; i++) if (!dfn[i]) tarjan(i);
		// for (i = 1; i <= top; i++) cout << col[i] << ' '; cout << endl;
		// for (i = 1; i <= top; i++) for (auto j: E[i]) printf("%d %d\n", i, j); cout << endl;
		for (i = 1; i <= (top >> 1); i++) if (col[i] == col[i + (top >> 1)]) { puts("-1"); break; }
		if (i > (top >> 1)) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j < K; j++) if (col[(j - 1) * n + i] > col[(j - 1) * n + i + (top >> 1)]) break;
				printf("%d ", j);
			}
			putchar('\n');
			// for (i = 1; i <= n; i++, cout << endl) for (j = 1; j < K; j++) printf("%d ", col[(j - 1) * n + i] > col[(j - 1) * n + i + (top >> 1)]);
		}
		clear();
	}
	return 0;
}