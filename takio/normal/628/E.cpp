#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 3010, mod = 1e9 + 7;

int n, m;
char s[N][N];
short l[N][N], r[N][N], c[N][N];
LL res;

void init () {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
//            res += (s[i][j] == 'z');
            l[i][j] = s[i][j] == 'z' ? l[i][j - 1] + 1 : 0;
            c[i][j] = s[i][j] == 'z' ? c[i + 1][j - 1] + 1 : 0;
        }
        for (int j = m; j >= 1; j--) {
            r[i][j] = s[i][j] == 'z' ? r[i][j + 1] + 1 : 0;
        }
    }
//    for (int i = 1; i <=n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << c[i][j] << ' ';
//        }
//        cout << endl;
//    }
}

pii a[N];
int an;
vector <pii> g[N * 2];
short tree[N * 2];

inline int f (int x) { return x & -x; }

inline void add (int x) {
//    cout << "add " <<x << endl;
    x = 2 * N - x - 1;
    if (x == 0) return;
    for (int i = x; i < N * 2; i += f (i)) {
        tree[i]++;
    }
}

inline int qry (int x) {
//    cout << "qry " <<x << endl;
    x = 2 * N - x - 1;
    int r = 0;
    for (int i = x; i; i -= f (i)) r += tree[i];
    return r;
}

void solve () {
    for (int i = 0; i < N * 2; i++) g[i].clear();
    memset (tree, 0, sizeof tree);
//    for (int i = 1; i <= an; i++) cout << a[i].xx <<' ' << a[i].yy << "   "; cout << endl;
    for (int i = 1; i <= an; i++) {
        int x = a[i].xx, y = a[i].yy, mn = min (l[x][y], c[x][y]);
//        cout << i - mn << ' ' << y << ' ' << -1 << endl;
//        cout << i << ' ' << y << ' ' << 1 << endl;
        g[i - mn].push_back (pii (y, -1));
        g[i].push_back (pii (y, 1));
    }
//    cout << endl;
    int tmp = 0;
    for (int i = 1; i <= an; i++) {
        int x = a[i].xx, y = a[i].yy;
        add (r[x][y] + y - 1);
        for (int j = 0; j < g[i].size(); j++) {
            res += g[i][j].yy * qry (g[i][j].xx);
//            cout << g[i][j].yy << ' ' << g[i][j].xx << ' ' << qry (g[i][j].xx) << endl;
//            tmp += g[i][j].yy * qry (g[i][j].xx);
        }
    }
//    cout << tmp << endl << endl;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", s[i] + 1);
    }
    init ();
    for (int k = 2; k <= n + m; k++) {
//        if (k <= n + 1) {
        an = 0;
        for (int i = k - 1, j = 1; j <= m && i >= 1; i--, j++) if (i <= n) {
            a[++an] = pii (i, j);
        }
        solve ();
//        }
    }
    cout << res << endl;
}