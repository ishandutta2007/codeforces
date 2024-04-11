#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second
const int MAXN = 505;
char s[11][MAXN]; int n, len[11];

int id (char c) { if (c >= 'A' && c <= 'Z') return c - 'A'; else return c - 'a' + 26; }
char rid (int x) { if (x < 26) return 'A' + x; else return 'a' + x - 26; }
int nex[11][MAXN][52], pos[11][52][2]; bool q[11][MAXN];
int tmp[52], f[52][1 << 10]; bool vis[52][1 << 10];
pii path[52][1 << 10];

int calc (int c, int st) {
	if (vis[c][st]) return f[c][st];
	vis[c][st] = 1;
	for (int i = 1; i <= n; i++) if (!pos[i][c][(st >> (i - 1)) & 1]) return 0;
	f[c][st] = 1; path[c][st] = make_pair(-1, -1);
	for (int i = 0; i < 52; i++) {
		int nexst = 0;
		for (int j = 1; j <= n; j++) {
			int now = (st >> (j - 1)) & 1; now = pos[j][c][now];
			if (nex[j][now][i] != len[j] + 1) nexst += q[j][nex[j][now][i]] << (j - 1);
			else { nexst = -1; break; }
		}
		if (nexst >= 0) {
			if (calc(i, nexst) + 1 > f[c][st]) {
				f[c][st] = calc(i, nexst) + 1;
				path[c][st] = make_pair(i, nexst);
			}
		}
	}
	return f[c][st];
}
void out (pii x) {
	if (x.fr == -1 && x.se == -1) return;
	putchar(rid(x.fr));
	out(path[x.fr][x.se]);
}

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j, k;
		for (i = 1; i <= n; i++) {
			scanf("%s", s[i] + 1); len[i] = strlen(s[i] + 1);
			for (j = 0; j < 52; j++) tmp[j] = len[i] + 1;
			for (j = len[i]; j >= 1; j--) {
				for (k = 0; k < 52; k++) nex[i][j][k] = tmp[k];
				tmp[id(s[i][j])] = j;
			}
			memset(tmp, 0, sizeof tmp);
			for (j = 1; j <= len[i]; j++) {
				q[i][j] = tmp[id(s[i][j])];
				pos[i][id(s[i][j])][q[i][j]] = j;
				tmp[id(s[i][j])] = j;
			}
		}
		int ans = 0; pii now = make_pair(-1, -1);
		for (i = 0; i < 52; i++) for (j = 0; j < (1 << n); j++) {
			if (calc(i, j) > ans) ans = calc(i, j), now = make_pair(i, j);
		}
		printf("%d\n", ans);
		out(now); putchar('\n');
		memset(nex, 0, sizeof nex); memset(pos, 0, sizeof pos); memset(q, 0, sizeof q);
		memset(f, 0, sizeof f); memset(vis, 0, sizeof vis); memset(path, 0, sizeof path);
	}
	return 0;
}