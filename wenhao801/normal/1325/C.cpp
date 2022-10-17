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

int n;
const int MAXN = 100100;

struct Edge {
    int nex;
    int to;
    int id;
} edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v, int w) {
    edge[++cnt].to = v; edge[cnt].nex = head[u];
    head[u] = cnt; edge[cnt].id = w;
}

int ans[MAXN];
bool f = false;

int main () {
    n = read();
    int i, j;
    for (i = 1; i < n; i++) { int u = read(), v = read(); add(u, v, i), add(v, u, i); }
        int k = 0;
    for (i = 1; i <= n; i++) {
        k = 0;
        for (j = head[i]; j; j = edge[j].nex) {
            k++;
        }
        if (k >= 3) {
            f = true;
            k = 1;
            for (j = head[i]; j; j = edge[j].nex) {
                if (k <= 3) ans[edge[j].id] = k;
                k++;
            }
            break;
        }
    }
    if (f) j = 4; else j = 1;
    for (i = 1; i < n; i++) if (!ans[i]) ans[i] = j, j++;
    for (i = 1; i < n; i++) printf("%d\n", ans[i] - 1);
    return 0;
}