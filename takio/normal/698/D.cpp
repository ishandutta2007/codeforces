#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 1100;

int a[N], b[N], x[N], y[N];

bool jug (int a, int b, int c, int d, int e, int f) {
    if (a > c) swap (a, c), swap (b, d);
    if (e < a || e > c) return 0;
    if (b < d) {
        if (f < b || f > d) return 0;
    } else {
        if (f > b || f < d) return 0;
    }
//    cout << a << ' ' << b << ' ' << c << ' ' << d<< ' ' << e<< ' '<< f << endl;
    return 1LL * (a - e) * (d - f) == 1LL * (c - e) * (b - f);
}

int now;

//bool cmp (int a, int b) {
//    return abs (x[a] - x[now]) + abs (y[a] - y[now]) > abs (x[a] - x[now]) + abs (y[a] - y[now]);
//}

struct node {
    int u, v, now, st;
    node () {}
    node (int u, int v, int now, int st) : u (u), v (v), now (now), st (st) {}
};

int vis[N], n, m, nowu, nowv;
stack <node> s[N];
vector <int> g[N][10];

int dfs (int k, int u, int v, int now, int st) {
//    cout << nowu << ' '<< nowv << endl;
//    cout << k << ' ' << u <<' ' << v << ' ' << now << ' ' << st << endl;
//    if (k == 2 && u == 1 && v == 2) exit (0);
//    cout << s[k - 1].u << ' ' << s[k - 1].v <<' ' << s[k - 1].now <<  ' ' << s[k - 1].st << endl;
    while (now < g[u][v].size() && vis[g[u][v][now]]) now++;
//    cout << k << ' ' << u <<' ' << v << ' ' << now << ' ' << st << endl << endl;
    if (now == g[u][v].size()) {
        if (u == nowu && v == nowv) return 1;
        vis[u] = 1;
        int res = dfs (k - 1, s[k - 1].top().u, s[k - 1].top().v, s[k - 1].top().now + 1, st);
        vis[u] = 0;
        return res;
    }
    s[k].push (node (u, v, now, st));
//    cout << st << endl;
    for (int i = 1; i <= m; i++) if ((st & (1 << i - 1)) == 0){
//        cout << st << ' '<< (1 << i - 1) << endl;
        if (dfs (k + 1, g[u][v][now], i, 0, st | (1 << i - 1))) {
//            cout << u << ' ' << v << ' ' << now << ' ' << st << endl;
            return 1;
        }
//        cout << k << ' '<< u << ' ' << v << ' ' << now << ' ' << st << endl << endl;
//        s[k] = node (u, v, now, st);
    }
    s[k].pop();
//    cout << "return" << endl;
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m ; j++) {
            for (int k = 1; k <= n; k++) if (i != k) {
                if (jug (x[i], y[i], a[j], b[j], x[k], y[k])) {
//                    cout << i << ' ' << j << ' ' << k << endl;
                    g[i][j].push_back (k);
                }
            }
            now = i;
//            sort (g[i][j].begin(), g[i][j].end(), cmp);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            nowu = i, nowv = j;
            memset (vis, 0, sizeof vis);
            for (int i = 1; i <= m; i++) while (!s[i].empty ()) s[i].pop();
            if (dfs (0, i, j, 0, 1 << j - 1)) {
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}