#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100100;

int f[N], d[N], inq[N], u[N], v[N], c[N], pre[N], ok[N], head[N], tot;

struct edge {
    int u, v, nx, c, id;
    edge () {}
    edge (int u, int v, int nx, int c, int id) : u (u), v (v) , nx (nx), c (c) , id (id) {}
}e[N * 2];

void add (int u, int v, int c, int id) {
    e[tot] = edge (u, v, head[u], c, id);
    head[u] = tot++;
}

void bfs () {
    queue <int> q;
    q.push (1);
    d[1] = f[1] = 0;
    while (!q.empty ()) {
        int u = q.front (); q.pop();
        inq[u] = 1;
        for (int i = head[u]; ~i; i = e[i].nx) {
            int v = e[i].v;
            if (d[v] > d[u] + 1 || (d[v] == d[u] + 1 && f[v] < f[u] + e[i].c)) {
                d[v] = d[u] + 1;
                f[v] = f[u] + e[i].c;
                pre[v] = i;
                if (!inq[v]) q.push (v);
            }
        }
    }
}

int main () {
    memset (head, -1, sizeof head);
    memset (d, 0x3f, sizeof d);
    memset (f, -1, sizeof f);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &u[i], &v[i], &c[i]);
        if (c[i]) cnt++;
        add (u[i], v[i], c[i], i);
        add (v[i], u[i], c[i], i);
    }
    bfs ();
    cout << cnt + d[n] - 2 * f[n] << endl;
    int t = n;
    while (t != 1) {
        if (e[pre[t]].c == 0) ok[e[pre[t]].id] = 1;
        else ok[e[pre[t]].id] = -1;
        t = e[pre[t]].u;
    }
    for (int i = 1; i <= m; i++) {
        if (ok[i] == 1 || ok[i] == 0 && c[i]) printf ("%d %d %d\n", u[i], v[i], !c[i]);
    }
}