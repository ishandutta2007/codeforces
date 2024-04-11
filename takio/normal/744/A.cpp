#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 110000, M = 1001000;

int v[N], c, flag, is[N];
vector <int> g[N];

void dfs (int u) {
    if (v[u]) return;
    if (is[u]) flag = 1;
    c++;
    v[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        dfs (g[u][i]);
    }
}

int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, k, x;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        scanf ("%d", &x);
        is[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    int an = 0, c2 = 0;
    for (int i = 1; i <= n; i++) if (!v[i]) {
        c = 0;
        flag = 0;
        dfs (i);
        if (flag) a[++an] = c;
        else c2 += c;
    }
    a[++an] = 0;
    sort (a + 1, a + 1 + an);
    a[an] += c2;
    int r = 0;
    for (int i = 1; i <= an; i++) {
        r += a[i] * (a[i] - 1) / 2;
    }
    cout << r - m << endl;
}