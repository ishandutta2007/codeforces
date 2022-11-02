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

const int N = 300010, M = 1000010, mod = 1e9 + 7;

int n, m, k, u, v;
int vis[N], lazy[N << 2], p[N];

//void init () {
//
//}

vector <int> g[N];

queue <int> q;

void updata (int rt, int l, int r, int tl, int tr) {
    if (tl > tr) return;
    if (lazy[rt]) return;
    if (l == r) {
        q.push (l);
        lazy[rt] = 1;
        return;
    }
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr);
    else if (m < tl) updata (rson, tl, tr);
    else updata (lson, tl, m), updata (rson, m + 1, tr);
    lazy[rt] = lazy[ls] & lazy[rs];
}

void solve (int u) {
//    cout << u << endl;
    while (!q.empty ()) q.pop();
    q.push (u);
    while (!q.empty ()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == 1) continue;
        updata (1 ,1 ,n, u, u);
//        cout << "   " << u << endl;
//        q.pop();
        for (int i = 0; i < g[u].size() - 1; i++) {
            updata (1 ,1 ,n, g[u][i] + 1, g[u][i + 1] - 1);
        }
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    init ();
    cin >> n >> m >> k;
    int all = n - 1;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
        if (u > v) swap (u, v);
        if (u == 1) p[v] = 1, all--;
        g[u].push_back (v);
        g[v].push_back (u);
    }
//    cout << all << endl;
    if (all < k) {
        cout << "impossible\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back (0);
        g[i].push_back (n + 1);
        sort (g[i].begin(), g[i].end());
    }
    int cnt = 0;
    updata (1 ,1 ,n, 1, 1);
    for (int i = 2; i <= n; i++) if (!p[i]) {
        int v = i;
        if (vis[v]) continue;
//        cout << v << endl;
        cnt++;
        solve (v);
    }
    for (int i = 2; i <= n; i++) if (!vis[i]) {
        cout << "impossible\n";
        return 0;
    }
//    cout << cnt << endl;
    if (cnt <= k) cout << "possible\n";
    else cout << "impossible\n";
}