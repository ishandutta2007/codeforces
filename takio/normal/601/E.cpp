#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 30100, K = 1010;

int n, k, w[N], v[N], is[N];

vector <int> g[N << 2];

struct A {
    int dp[K];
    void init () { memset (dp, 0, sizeof dp); }
    void add (int id) {
        for (int i = k; i >= v[id]; i--) dp[i] = max (dp[i], dp[i - v[id]] + w[id]);
    }
} now, st[30];

//int getid (int l, int r) {
//    return l + r | l != r;
//}

//void build (int l, int r) {
//    int rt = getid (l, r);
//    a[rt].init ();
//    if (l == r) return;
//    int m = l + r >> 1;
//    build (l, m); build (m + 1, r);
//}

void updata (int rt, int l, int r, int tl, int tr, int id) {
//    cout << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (tl <= l && r <= tr) {
        g[rt].push_back (id);
        return;
    }
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr, id);
    else if (m < tl) updata (rson, tl, tr, id);
    else updata (lson, tl, m, id), updata (rson, m + 1, tr, id);
//    updata (rson, m + 1, r, id);
}

const int p = 1e7 + 19, q = 1e9 + 7;

void getres () {
    LL res = 0;
    for (int i = k; i >= 1; i--) {
        res *= p;
        res += now.dp[i];
//        cout << now.dp[i] << " ";
        res %= q;
    }
//    cout << endl;
    printf ("%d\n", (int)res);
}

void query (int rt, int l, int r, int d) {
//    cout << l << ' ' << r << endl;
    for (int i = 0; i < g[rt].size(); i++) {
        now.add (g[rt][i]);
//        cout << rt << ' ' << g[rt][i] <<endl;
    }
    for (int i = 1; i <= k; i++) st[d].dp[i] = now.dp[i];
//    if (l <= 5 && 5 <= r) {
//        for (int i = 0; i < g[rt].size(); i++) {
//            cout << g[rt][i] << " ";
//            now.add (g[rt][i]);
    //        cout << rt << ' ' << g[rt][i] <<endl;
//        } cout << endl;
//        for (int i = 1; i <= k; i++) {
//            cout << now.dp[i] << " ";
    //        cout << rt << ' ' << g[rt][i] <<endl;
//        } cout << endl;
//    }
    if (l == r) {
//        cout << l << endl;
//        for (int i = 1; i <= k; i++) cout << now.dp[i] << ' '; cout << endl;
        if (is[l]) {
            getres ();
//            cout << l << endl;
        }
        return;
    }
    int m = l + r >> 1;
    query (lson, d + 1);
//    for (int i = 1; i <= k; i++) now.dp[i] = st[d].dp[i];
    for (int i = 1; i <= k; i++) now.dp[i] = st[d].dp[i];
    query (rson, d + 1);
//    for (int i = 1; i <= k; i++) now.dp[i] = st[d].dp[i];
}

int x[N], y[N], t[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &w[i], &v[i]);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) x[i] = 1, y[i] = q + 1;
    for (int i = 2; i <= q + 1; i++) {
        scanf ("%d", &t[i]);
        if (t[i] == 1) {
            n++;
            scanf ("%d%d", &w[n], &v[n]);
            x[n] = i; y[n] = q + 1;
        } else if (t[i] == 2) {
            int xx;
            scanf ("%d", &xx);
            y[xx] = i;
        } else is[i] = 1;
    }
//    build (1, n);
    for (int i = 1; i <= n; i++) {
//        cout << i << ' ' << x[i] << ' ' << y[i] << endl;
//        cout << i << ' ' << v[i] << ' ' << w[i] << endl;
        updata (1, 1, q + 1, x[i], y[i], i);
    }
    now.init();
    query (1, 1, q + 1, 0);
}