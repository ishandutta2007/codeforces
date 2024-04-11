#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#define pii pair <int, int>
#define piii pair <pii, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define xx first
#define yy second
using namespace std;

const int N = 200100;
int n, m, k, qn;
int mn[N << 2], res[N];
vector <int> g[N];
struct qry2 {
    int x, y1, y2, id;
    qry2 () {}
    qry2 (int x, int y1, int y2, int id) : x(x), y1(y1), y2(y2), id(id) {}
};
vector <qry2> s[N];

void init () {
    memset (mn, 0, sizeof mn);
    for (int i = 1; i <= n; i++) g[i].clear(), s[i].clear();
}

void updata (int rt, int l, int r, int x, int c) {
    if (l == r) { mn[rt] = c; return; }
    int m = (l + r) >> 1;
    if (x <= m) updata (lson, x, c);
    else updata (rson, x, c);
    mn[rt] = min (mn[ls], mn[rs]);
}

int query (int rt, int l, int r, int tl, int tr) {
//    cout << rt << ' ' << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (tl <= l && r <= tr) { return mn[rt]; }
    int m = (l + r) >> 1;
    if (tr <= m) return query(lson, tl, tr);
    else if (m < tl) return query(rson, tl, tr);
    else return min (query (lson, tl, m), query(rson, m + 1, tr));
}

struct node {
    int x, y;
    void input () { scanf ("%d%d", &x, &y) ;}
} a[N];

struct qry {
    int x1, y1, x2, y2, id;
    void input (int x) { scanf ("%d%d%d%d", &x1, &y1, &x2, &y2); id = x; }
} q[N];

void solve () {
    init ();
    for (int i = 1; i <= k; i++) {
        g[a[i].x].push_back (a[i].y);
    }
    for (int i = 1; i <= qn; i++) {
        s[q[i].x2].push_back (qry2 (q[i].x1, q[i].y1, q[i].y2, q[i].id));
    }
    for (int i = 1; i <= n; i++) {
//        cout << "i " << i << endl;
        int sz = g[i].size();
        for (int j = 0; j < sz; j++) {
            updata (1, 1, m, g[i][j], i);
//            for (int i = 1; i <= 7; i++) cout << mn[i] << ' '; cout << endl;
//            cout << "up " << g[i][j] << ' ' << i << endl;
        }
        sz = s[i].size();
        for (int j = 0; j < sz; j++)
        if (!res[s[i][j].id])
        {
            int tmp = query (1, 1, m, s[i][j].y1, s[i][j].y2);
            if (tmp >= s[i][j].x) res[s[i][j].id] = 1;
//            cout << "qry " << s[i][j].x << ' ' << s[i][j].y1 << ' ' <<  s[i][j].y2 << ' ' << tmp << endl;
        }
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k >> qn;
    for (int i = 1; i <= k; i++) {
        a[i].input();
    }
    for (int i = 1; i <= qn; i++) {
        q[i].input(i);
    }
    solve ();
    swap (n, m);
    for (int i = 1; i <= k; i++) {
        swap (a[i].x, a[i].y);
//        cout << a[i].x << ' ' << a[i].y << endl;
    }
    for (int i = 1; i <= qn; i++) {
        swap (q[i].x1, q[i].y1), swap (q[i].x2, q[i].y2);
//        cout << q[i].x1 << ' ' << q[i].y1 << ' ' << q[i].x2 << ' ' << q[i].y2 << endl;
    }
    solve ();
    for (int i = 1; i <= qn; i++) {
        if (res[i]) printf ("YES\n");
        else printf ("NO\n");
    }
}