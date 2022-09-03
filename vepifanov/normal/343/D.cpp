#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int p[500000];
int q[500000];
int ct;
int tree[2][1 << 21];
int add[2][1 << 21];
vi v[500000];

int go (int x, int p) {
    ::p[x] = ct;
    ct++;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p)
            go (v[x][i], x);
    q[x] = ct - 1;
    re 0;
}

int push (int t, int x, int l, int r) {
    if (add[t][x]) {
        if (l != r) {
            add[t][x * 2 + 1] = max (add[t][x * 2 + 1], add[t][x]);
            add[t][x * 2 + 2] = max (add[t][x * 2 + 2], add[t][x]);
        }   
        tree[t][x] = max (tree[t][x], add[t][x]);
        add[t][x] = 0;
    }
    re 0;
}

int upd (int t, int x, int l, int r, int lc, int rc, int y) {
    push (t, x, l, r);
    if (r < lc || l > rc) re tree[t][x];
    if (l >= lc && r <= rc) {
        add[t][x] = y;
        push (t, x, l, r);
        re tree[t][x];
    }
    int s = (l + r) / 2;
    re tree[t][x] = max (upd (t, x * 2 + 1, l, s, lc, rc, y), upd (t, x * 2 + 2, s + 1, r, lc, rc, y));
}

int get (int t, int x, int l, int r, int lc, int rc) {
    push (t, x, l, r);
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[t][x];
    int s = (l + r) / 2;
    re max (get (t, x * 2 + 1, l, s, lc, rc), get (t, x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    go (0, -1);
    memset (tree, 0, sizeof (tree));
    memset (add, 0, sizeof (add));
    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        if (a == 0)
            upd (0, 0, 0, n - 1, p[b], q[b], i);
        else
        if (a == 1)
            upd (1, 0, 0, n - 1, p[b], p[b], i);
        else {
            int x = get (0, 0, 0, n - 1, p[b], p[b]);
            int y = get (1, 0, 0, n - 1, p[b], q[b]);
            if (x == 0 && y == 0 || x < y) printf ("0\n"); else printf ("1\n");
        }
    }
    return 0;
}