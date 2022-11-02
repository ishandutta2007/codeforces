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
using namespace std;

const int N = 1000010;

vector <piii> all, tmp;
vector <int> res[N];
int fa[N], mx1[N], mx2[N], mx[N];

int getfa (int x) {
    int f = x;
    while (fa[f] != f) f = fa[f];
    while (fa[x] != x) {
        int t = fa[x];
        fa[x] = f;
        x = t;
    }
    return f;
}

void add (int x, int y) {
    x = getfa (x);
    y = getfa (y);
    if (x == y) return;
    fa[x] = y;
}

bool cmp (piii a, piii b) {
    if (a.yy.yy == b.yy.yy) return a.yy.xx < b.yy.xx;
    return a.yy.yy < b.yy.yy;
}

void solve (int l, int r) {
//    cout << l << ' ' << r << endl;
    for (int i = l + 1; i <= r; i++) {
        if (all[i - 1].yy.xx == all[i].yy.xx) {
            add (i - 1, i);
        }
    }
    tmp.clear();
    for (int i = l; i <= r; i++) {
//        pii t = all[i].yy;
        tmp.push_back (piii (i, all[i].yy));
    }
    sort (tmp.begin(), tmp.end(), cmp);
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i - 1].yy.yy == tmp[i].yy.yy) {
            add (tmp[i - 1].xx, tmp[i].xx);
        }
    }
    for (int i = 0; i < tmp.size(); i++) {
        int id = getfa (tmp[i].xx), x = tmp[i].yy.xx, y = tmp[i].yy.yy;
//        cout << id << endl;
        mx[id] = max (mx[id], mx1[x]);
        mx[id] = max (mx[id], mx2[y]);
    }
    for (int i = 0; i < tmp.size(); i++) {
        int id = getfa (tmp[i].xx), x = tmp[i].yy.xx, y = tmp[i].yy.yy;
        res[x][y] = mx[id] + 1;
        mx1[x] = max (mx1[x], mx[id] + 1);
        mx2[y] = max (mx2[y], mx[id] + 1);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, x;
    cin >> n >> m;
    all.push_back (piii (0, pii (0, 0)));
    for (int i = 1; i <= n; i++) {
        res[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            scanf ("%d", &x);
            all.push_back (piii (x, pii (i, j)));
        }
    }
    for (int i = 0; i < N; i++) fa[i] = i;
    sort (all.begin(), all.end());
    int sz = n * m;
    for (int i = 1; i <= sz;) {
        int j = i + 1;
        while (j <= sz && all[j].xx == all[i].xx) j++;
        solve (i, j - 1);
        i = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf ("%d ", res[i][j]);
        }
        printf ("\n");
    }
}