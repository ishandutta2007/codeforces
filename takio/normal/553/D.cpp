#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define pb push_back
using namespace std;

const int N = 100100;
const double eps = 1e-10;

struct edge {
    int v, nx;
    edge (int v = 0, int nx = 0) : v (v), nx (nx) {}
} e[N * 2];

int head[N], tot;
int n, m, k;

void add (int u, int v) {
    e[tot] = edge (v, head[u]);
    head[u] = tot++;
}

int a[N], b[N], vis[N];
vector <int> g[N], f;

int jug (double now) {
//    cout << now << endl;
    for (int i = 1; i <= n; i++) a[i] = g[i].size(), b[i] = ceil(a[i] * now - eps);
    for (int i = 1; i <= n; i++) {
//        cout << i << ' ' << a[i] << ' ' << b[i] << endl;
    }
    queue <int> q;
    memset (vis, 0, sizeof vis);
    int cnt = n;
    for (int i = 0; i < f.size(); i++) {
        q.push (f[i]);
//        cout << "in " << f[i] << endl;
        vis[f[i]] = 1;
        cnt--;
    }
    while (!q.empty ()) {
        int u = q.front();
        q.pop();
//        cout << u << endl;
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i];
            if (vis[v]) continue;
            a[v]--;
//            cout << u << ' ' << v << endl;
            if (a[v] < b[v]) {
//                cout << "in " << v << endl;
                q.push (v);
                vis[v] = 1;
                cnt--;
            }
        }
    }
    return cnt;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (head, -1, sizeof head);
    tot = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf ("%d", &x);
        f.pb (x);
    }
    while (m--) {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u].pb (v);
        g[v].pb (u);
    }
    double s = 0, e = 1;
    int T = 150;
    while (T--) {
        double m = (s + e) / 2;
        if (jug (m)) s = m;
        else e = m;
//        cout << s <<' ' << e << endl;
    }
//    cout <<s << endl;
    cout << jug (s - eps) << endl;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        printf ("%d ", i);
    }
}