#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 100100;

int head[N], c[N], tot;

struct edge {
    int v, nx, c;
    edge () {}
    edge (int v, int nx, int c) : v (v), nx (nx), c (c) {}
} e[N * 2];

void add (int u, int v, int c) {
    e[tot] = edge (v, head [u], c);
    head [u] = tot++;
}

int dfs (int u, int now) {
//    cout << u << ' ' << now << endl;
    if (c[u]) {
        return now == c[u];
    }
    c[u] = now;
    for (int i = head[u]; ~i; i = e[i].nx) {
        if (dfs (e[i].v, now ^ e[i].c) == 0) return 0;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (head, -1, sizeof head);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v, d;
        scanf ("%d%d%d", &u, &v, &d);
        if (d == 0) d = 3; else d = 0;
        add (u, v, d);
        add (v, u, d);
    }
    int cnt = -1;
    for (int i = 1; i <= n; i++) if (!c[i]) {
//        cout << i << endl;
        cnt++;
        if (dfs (i, 1) == 0) { cout << 0 << endl; return 0; }
    }
    int r = 1;
    while (cnt--) (r *= 2) %= (int)(1e9 + 7);
    cout << r << endl;
}