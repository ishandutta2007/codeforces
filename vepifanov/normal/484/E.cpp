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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 2500000;

int n;
int m;
int o = 0;
vii v;
pair<ii, ii> tree[N];
ii child[N];
int root[100000];

pair<ii, ii> merge (pair<ii, ii> a, pair<ii, ii> b) {
    pair<ii, ii> c;
    c.fi.fi = a.fi.fi + b.fi.fi;
    c.fi.se = max (max (a.fi.se, b.fi.se), a.se.se + b.se.fi);
    c.se.fi = a.se.fi + int (a.se.fi == a.fi.fi) * b.se.fi;
    c.se.se = b.se.se + int (b.se.se == b.fi.fi) * a.se.se;
    re c;
}

int build (int l, int r) {
    int x = o++;
    if (l == r) {
        tree[x] = mp (mp (1, 0), mp (0, 0));
        re x;
    }   
    int s = (l + r) / 2;
    int a = build (l, s);
    int b = build (s + 1, r);
    child[x] = mp (a, b);
    tree[x] = merge (tree[a], tree[b]);
    re x;
}

int upd (int x, int l, int r, int y) {
    int tmp = o++;
    tree[tmp] = tree[x];
    child[tmp] = child[x];
    x = tmp;
    if (l == r) {
        tree[x] = mp (mp (1, 1), mp (1, 1));
        re x;
    }   
    int s = (l + r) / 2;
    int a = child[x].fi, b = child[x].se;
    if (y <= s)
        a = upd (a, l, s, y);
    else
        b = upd (b, s + 1, r, y);
    child[x] = mp (a, b);
    tree[x] = merge (tree[a], tree[b]);
    re x;
}

pair<ii, ii> get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re mp (mp (0, 0), mp (0, 0));
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re merge (get (child[x].fi, l, s, lc, rc), get (child[x].se, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v.pb (mp (x, i));
    }
    int r = build (0, n - 1);
    sort (all (v));
    reverse (all (v));
    for (int i = 0; i < n; i++) {
        r = upd (r, 0, n - 1, v[i].se);
        root[i] = r;
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        int l = -1, r = n - 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (get (root[s], 0, n - 1, a, b).fi.se >= c) r = s; else l = s;
        }
        printf ("%d\n", v[r].fi);
    }
    return 0;
}