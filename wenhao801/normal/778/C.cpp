#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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
int n, ch[MAXN][26], dep[MAXN], siz[MAXN];
vector <int> pt[MAXN];
struct opr { int x, c; } t[MAXN]; int top;

void pre (int x, int f) {
    dep[x] = dep[f] + 1; pt[dep[x]].push_back(x); siz[x] = 1;
    for (int i = 0; i < 26; i++) if (ch[x][i]) pre(ch[x][i], x), siz[x] += siz[ch[x][i]];
}

int tmp = 0;
void mergeto (int x, int y) {
    for (int i = 0; i < 26; i++) if (ch[y][i]) {
        if (ch[x][i]) mergeto(ch[x][i], ch[y][i]), ++tmp;
        else {
            t[++top] = {x, i};
            ch[x][i] = ch[y][i];
        }
    }
}

int main () {
    n = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read(); char c[2]; scanf("%s", c);
        ch[u][c[0] - 'a'] = v;
    }
    pre(1, 0);
    int ans = n, out = 1;
    for (i = 1; !pt[i + 1].empty(); ++i) {
        int cur = 0;
        for (auto x: pt[i]) {
            top = 0; tmp = 0;
            int mx = 0;
            for (int j = 0; j < 26; j++) if (ch[x][j]) mx = siz[ch[x][j]] > siz[mx] ? ch[x][j] : mx, ++cur;
            if (!siz[mx]) continue;
            for (int j = 0; j < 26; j++) if (ch[x][j] && ch[x][j] != mx)
                mergeto(mx, ch[x][j]);
            cur += tmp;
            for (top; top >= 1; top--) ch[t[top].x][t[top].c] = 0;
        }
        if (n - cur < ans) ans = n - cur, out = i;
    }
    printf("%d\n%d\n", ans, out);
    return 0;
}