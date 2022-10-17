#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second
const int MAXN = 1010, inf = 0x3f3f3f3f;
const pii to[8] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

int disa[MAXN][MAXN], disb[MAXN][MAXN], dis[MAXN][MAXN], n, m;
bool valid (pii x) { return x.fr >= 1 && x.fr <= n && x.se >= 1 && x.se <= m; }

queue <pii> q;
void bfs (int sx, int sy) {
    int i, j;
    memset(dis, 0x3f, sizeof dis);
    q.push(pii(sx, sy)); dis[sx][sy] = 0;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (i = 0; i < 8; i++) {
            pii nex = pii(cur.fr + to[i].fr, cur.se + to[i].se);
            if (valid(nex) && dis[nex.fr][nex.se] == inf) {
                dis[nex.fr][nex.se] = dis[cur.fr][cur.se] + 1;
                q.push(nex);
            }
        }
    }
}

int xa, ya, xb, yb; bool choice = 0;
void proc (int x, int y) {
    if (!choice) {
        xa = x, ya = y, printf("%d %d\n", x, y), fflush(stdout);
        if (x == (n >> 1) && y == (m >> 1)) exit(0);
        if (xa == xb && ya == yb) exit(0);
        xb = read(), yb = read();
    } else {
        xb = x, yb = y, printf("%d %d\n", x, y), fflush(stdout);
        if (x == (n >> 1) + 1 && y == (m >> 1)) exit(0);
        if (xa == xb && ya == yb) exit(0);
        xa = read(), ya = read();
    }
    for (int i = 0; i < 8; i++) if (xa + to[i].fr == xb && ya + to[i].se == yb) {
        if (!choice) printf("%d %d\n", xb, yb); else printf("%d %d\n", xa, ya);
        fflush(stdout); exit(0);
    }
}
void go (int x, int y, bool c) {
    while (x != (n >> 1) + c || y != (m >> 1)) {
        int tx, ty, dt = inf;
        for (int i = 0; i < 8; i++) {
            pii nex = pii(x + to[i].fr, y + to[i].se);
            if (valid(nex) && dt > (!c ? disa[nex.fr][nex.se] : disb[nex.fr][nex.se]))
                dt = !c ? disa[nex.fr][nex.se] : disb[nex.fr][nex.se], tx = nex.fr, ty = nex.se;
        }
        x = tx, y = ty; proc(x, y);
    }
}

int main () {
    n = read(), m = read(); int i, j;
    xa = read(), ya = read(), xb = read(), yb = read();
    bfs(n >> 1, m >> 1); memcpy(disa, dis, sizeof dis);
    bfs((n >> 1) + 1, m >> 1); memcpy(disb, dis, sizeof dis);
    if (((xa + ya) & 1) == ((xb + yb) & 1)) {
        if (disb[xb][yb] < disa[xa][ya]) {
            puts("BLACK"), fflush(stdout); choice = 1; xa = read(), ya = read();
            go(xb, yb, 1); return 0;
        } else if (disa[xb][yb] <= disa[xa][ya]) {
            puts("BLACK"), fflush(stdout); choice = 1; xa = read(), ya = read();
            go(xb, yb, 0); go(xb, yb, 1); return 0;
        } else {
            puts("WHITE"); fflush(stdout); choice = 0;
            go(xa, ya, 0); return 0;
        }
    } else {
        if (disb[xb][yb] >= disa[xa][ya]) {
            puts("WHITE"), fflush(stdout); choice = 0;
            go(xa, ya, 0); return 0;
        } else if (disb[xa][ya] <= disb[xb][yb] + 1) {
            puts("WHITE"), fflush(stdout); choice = 0;
            go(xa, ya, 1); go(xa, ya, 0); return 0;
        } else {
            puts("BLACK"), fflush(stdout); choice = 1; xa = read(), ya = read();
            go(xb, yb, 1); return 0;
        }
    }
    return 0;
}