#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 200010;
//const ULL 1LL = 1;
vector <int> g[N];
int sz[N], res;

int dfs (int u, int fa) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
//        sz[u]++;
        sz[u] += dfs (v, u);
    }
//    cout << u << ' ' << fa <<' ' <<sz[u] << endl;
    if (sz[u] > 1) {
        res += sz[u] - 1;
        return 0;
    }
    return 1;
}

int main () {
//    srand (time (0));
//    freopen ("in.txt", "r", stdin);
    int n;
    LL x, y;
    cin >> n >> x >> y;
    if (n == 2) {
        cout << x;
        return 0;
    }
    if (n == 3) {
        if (x < y) cout << 2 * x;
        else cout << x + y;
        return 0;
    }
    if (x == y) {
        cout << 1LL * (n - 1) * x;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    int rt = 1LL * rand () * rand () % n + 1;
    if (x < y) {
        res = 0;
        if (dfs (rt, 0)) res ++;
//        for (int i = 1; i <= n; i++) if (g[i].size() == 1) res++;
        res--;
//        cout << res << endl;
        cout << y * res + x * (n - 1 - res);
    } else {
        int f = 0;
        for (int i = 1; i <= n; i++) if (g[i].size() == n - 1) {
            f = 1;
        }
        if (f) cout << 1LL * y * (n - 2) + x;
        else cout << 1LL * y * (n - 1);
    }
}