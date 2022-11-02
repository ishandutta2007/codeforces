#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>
#define LL long long
using namespace std;

const int N = 20100, mod = 1e9 + 7;

int head[2][N], tot[2], a[N], d;

struct edge {
    int v, nx;
    edge () {}
    edge (int v, int nx) : v (v), nx (nx) {}
} e[2][N * 2], e2[N * 2];

void add (int k, int u, int v) {
    e[k][tot[k]] = edge (v, head[k][u]);
    head[k][u] = tot[k]++;
}

void dfs (int u, int fa, int c, int r) {
    for (int i = head[0][u]; i != -1; i = e[0][i].nx) {
        int v = e[0][i].v;
        if (v == fa) continue;
        if ((a[v] > c || (a[v] == c && v < r)) && a[v] <= c + d) {
            add (1, v, u), add (1, u, v);
            dfs (v, u, c, r);
        }
    }
}

int dfs2 (int u, int fa) {
    LL res = 1;
    for (int i = head[1][u]; i != -1; i = e[1][i].nx) {
        int v = e[1][i].v;
        if (v == fa) continue;
        (res *= dfs2 (v, u) + 1) %= mod;
    }
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (head, -1, sizeof head);
    tot[0] = 0;
    int n, u, v;
    cin >> d >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        add (0, u, v);
        add (0, v, u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset (head[1], -1, sizeof head[1]);
        tot[1] = 0;
        dfs (i, -1, a[i], i);
//        cout << i << ' ' << dfs2 (i, -1) << endl;
        (res += dfs2 (i, -1)) %= mod;
    }
    cout << res << endl;
}