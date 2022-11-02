#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

const int N = 100100;
vector <int> g[N];

int dfs2 (int u, int fa) {
    int cnt = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        if (dfs2 (v, u) > 1) return 2;
        cnt++;
    }
    if (cnt > 1) return 2;
    return 1;
}

int dfs (int u, int fa) {
//    cout << fa << ' ' << u << endl;
    int c[10], cnt = 0;
    memset (c, 0, sizeof c);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        int t = dfs (v, u);
//        cout << v << ' ' << t << endl;
        if (t < 0) return t;
        c[t]++;
        cnt++;
    }
    if (cnt == 0) return 1;
    int mx = 1;
    for (int i = 1; i <= 5; i++) if (c[i]) mx = i;
//    cout << u << ' ' << mx << endl;
    if (mx == 4) {
//        cout << "xx";
        if (fa) c[dfs2 (fa, u)]++;
        if (c[1] <= 2 && c[2] == 0 && c[3] == 0 && c[4] == 1) cout << "Yes";
        else cout << "No";
        return -2;
    }
    if (cnt == 1) {
        if (mx == 1) return 1;
        return 3;
    }
    if (mx == 1) {
        if (c[1] == 2) return 2;
        return 3;
    }
    if (mx == 2) return 3;
    if (mx == 3) {
        if (c[3] >= 3) return -1;
        if (c[3] == 2) return 4;
        return 3;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < g[i].size(); j++) {
//            cout << i << ' ' << g[i][j] << endl;
//        }
//    }
//    for (int i = 1; i <= n; i++) cout << i << ' ' << dfs (i, 0) << endl;
    int tmp = dfs (1, 0);
    if (tmp == -1) cout << "No";
    else if (tmp > 0) cout << "Yes";
}