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

const int MAXN = 200200;
int n, m; vector <int> a[MAXN], pre, suf;

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read();
        int i, j;
        for (i = 1; i <= n; i++) {
            a[i].resize(m + 1);
            for (j = 1; j <= m; j++) a[i][j] = read();
        }
        int U = 1, V = 1;
        for (i = 1; i <= n; i++) {
			pre.clear(), suf.clear();
			pre.resize(m + 2), suf.resize(m + 2);
			pre[1] = a[i][1]; for (j = 2; j <= m; j++) pre[j] = max(pre[j - 1], a[i][j]);
			suf[m] = a[i][m]; for (j = m - 1; j >= 1; j--) suf[j] = min(suf[j + 1], a[i][j]);
			for (j = 1; j < m; j++) if (pre[j] > suf[j + 1]) {
				U = j;
				for (int k = m; k > j; k--) if (a[i][k] < a[i][j]) { V = k; break; }
				break;
			}
			if (j == m) continue;
            // printf("%d %d\n", u, v);
            for (j = 1; j <= n; j++) swap(a[j][U], a[j][V]);
			break;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j < m; j++) if (a[i][j] > a[i][j + 1]) break;
            if (j < m) break;
        }
        if (i > n) printf("%d %d\n", U, V); else puts("-1");
        for (i = 1; i <= n; i++) a[i].clear();
    }
    return 0;
}