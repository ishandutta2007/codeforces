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

const int MAXN = 110;
int n, K; vector <int> a[MAXN];
int id[MAXN], cur; bool vis[MAXN];
bool cmp (int x, int y) { return a[x][cur] < a[y][cur]; }

pair <int, int> ans[MAXN];

int main () {
    n = read(), K = read(); int i, j;
    for (i = 1; i <= n * K; i++) {
        int x = read();
        a[x].push_back(i);
    }
    for (i = 1; i <= n; i++) id[i] = i;
    for (cur = 1; 1; cur++) {
        bool fin = 0;
        int lim = n / (K - 1) + (bool(n % (K - 1))); i = 1;
        sort(id + 1, id + n + 1, cmp);
        while (lim) {
            for (i; vis[id[i]] && i <= n; i++);
            if (i > n) { fin = 1; break; }
            else vis[id[i]] = 1, ans[id[i]] = make_pair(a[id[i]][cur - 1], a[id[i]][cur]);
            --lim;
        }
        if (fin) break;
    }
    for (i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}