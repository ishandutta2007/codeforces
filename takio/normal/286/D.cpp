#include <bits/stdc++.h>
#define lson ls[rt], l, m
#define rson rs[rt], m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second

using namespace std;

const int N = 400100, M = 15001000, MX = 1e9;

int ls[M], rs[M], ok[M], tot, root;

int newnode () {
    ok[tot] = ls[tot] = rs[tot] = 0;
    return tot++;
}

void build () {
    tot = 1;
    root = newnode ();
}

void up (int rt) {
    if (ok[ls[rt]] == 2 && ok[rs[rt]] == 2) ok[rt] = 2;
    else ok[rt] = ok[ls[rt]] || ok[rs[rt]];
}

void updata (int &rt, int l, int r, int tl, int tr) {
//    cout << "up " << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (rt == 0) rt = newnode();
    if (ok[rt] == 2) return;
    if (tl <= l && r <= tr) { ok[rt] = 2; return; }
    int m = l + r >> 1;
    if (tl <= m) updata (lson, tl, tr);
    if (m < tr) updata (rson, tl, tr);
    up (rt);
}

vector <pii> g;
//int b[N * 2];

void query (int rt, int l, int r, int tl, int tr) {
//    cout << "qry " << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (rt == 0) return;
    if (ok[rt] == 2) {
        g.push_back (pii (max (tl, l), min (tr, r)));
        return;
    }
    if (ok[rt] == 0) return;
    int m = l + r >> 1;
    if (tl <= m) query (lson, tl, tr);
    if (m < tr) query (rson, tl, tr);
}

struct line {
    int l, r, t;
    line (int l = 0, int r = 0, int t = 0) : l (l), r (r), t (t) {}
} a[N], c[N];

bool cmp (line a, line b) { return a.t < b.t; }

map <int, vector <int> > mp;
set <int> st;
map <int, vector <int> > :: iterator it;

void up (vector <int> &a, int c) {
    if (a.size() == 0) a.push_back (c);
    else a[0] += c;
}

int res[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
//    int bn = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &c[i].l, &c[i].r, &c[i].t);
        c[i].r--;
//        b[++bn] = c[i].l;
//        b[++bn] = c[i].r;
    }
    sort (c + 1, c + 1 + m, cmp);
//    sort (b + 1, b + 1 + bn);
//    bn = unique (b + 1, b + 1 + bn) - b - 1;
//    for (int i = 1; i <= bn; i++) cout << b[i] << ' '; cout << endl;
    build ();
    int an = 0;
    for (int i = 1; i <= m; i++) {
        int tl = c[i].l;
        int tr = c[i].r;
        g.clear ();
//        cout << tl << ' ' << tr << endl;
        query (root, 0, MX, tl, tr);
        int now = tl;
        for (int j = 0; j < (int)g.size(); j++) {
//            cout << i << "    " <<  g[j].xx << ' ' << g[j].yy << endl;
            if (g[j].xx != now) {
//                cout << now << ' ' << g[j].xx - 1 << endl;
                a[++an] = line (now, g[j].xx - 1, c[i].t);
            }
            now = g[j].yy + 1;
        }
        if (now <= tr) a[++an] = line (now, tr, c[i].t);
//        cout << tl << ' ' << tr << endl;
        updata (root, 0, MX, tl, tr);
//        cout <<tl << ' ' << tr << endl;
    }
    m = an;
    for (int i = 1; i <= m; i++) {
//        cout << a[i].l << ' ' << a[i].r << ' ' << a[i].t << endl;
//        cout << a[i].t - a[i].r << ' ' << 1 << endl;
//        cout << a[i].t - a[i].l + 1 << ' ' << -1 << endl;
        up (mp[a[i].t - a[i].r], 1);
        st.insert(a[i].t - a[i].r);
        up (mp[a[i].t - a[i].l + 1], -1);
        st.insert(a[i].t - a[i].l + 1);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf ("%d", &x);
        mp[x].push_back (i);
    }
    int now = 0, pre = 0, sum = 0;
    for (it = mp.begin(); it != mp.end (); it++) {
        int pos = (*it).xx;
        vector <int> &a = (*it).yy;
        sum += now * (pos - pre);
        int f = 0;
//        cout << "xxx " << pos << ' ' << sum << endl;
        if (st.find (pos) != st.end ()) now += a[0], sum += a[0], f++;
        for (int i = f; i < (int)a.size(); i++) {
            res[a[i]] = sum;
        }
        pre = pos;
    }
    for (int i = 1; i <= n; i++) printf ("%d\n", res[i]);
}