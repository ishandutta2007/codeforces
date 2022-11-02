#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200010;

vector <pii> g[N];
vector <int> r[N];
int d[N];

void dfs (int u, int fa, int x) {
//    cout << u << ' ' << fa << ' ' << x << endl;
    int c = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].xx;
        if (v == fa) continue;
        c++;
        if (c == x) c++;
        r[c].push_back (g[u][i].yy);
        dfs (v, u, c);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, mx = 0, u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        d[u]++;
        d[v]++;
        g[u].push_back (pii (v, i));
        g[v].push_back (pii (u, i));
        mx = max (mx, d[u]);
        mx = max (mx, d[v]);
    }
    dfs (1, 0, 0);
    cout << mx << endl;
    for (int i = 1; i <= mx; i++) {
        printf ("%d", r[i].size());
        for (int j = 0; j < r[i].size(); j++) {
            printf (" %d", r[i][j]);
        }
        printf ("\n");
    }
}