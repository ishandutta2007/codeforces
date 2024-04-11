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
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second

const int MAXN = 5050;
char a[MAXN], ans[MAXN]; int n, S = 1;
bool vis[MAXN][MAXN];
vector <pii> cur, tmp;

int main () {
	scanf("%s", a + 1); n = strlen(a + 1);
	while ((S << 1) <= n) S <<= 1;
	int i, j; cur.push_back(pii(0, S - 1));
	for (i = 1; i <= n - S + 1; i++) {
		while (!cur.empty()) {
			int x = cur.back().fr, s = cur.back().se; cur.pop_back();
			if (n - x != s) tmp.push_back(pii(x, s));
			for (j = 0; j <= 12; j++) if (((s >> j) & 1) && !vis[x + (1 << j)][s - (1 << j)]) {
				vis[x + (1 << j)][s - (1 << j)] = 1;
				cur.push_back(pii(x + (1 << j), s - (1 << j)));
			}
		}
		ans[i] = 'z'; for (auto j: tmp) ans[i] = min(ans[i], a[j.fr + 1]);
		for (auto j: tmp) if (a[j.fr + 1] == ans[i]) cur.push_back(pii(j.fr + 1, j.se)), vis[j.fr + 1][j.se] = 1;
		tmp.clear();
	}
	puts(ans + 1);
	return 0;
}