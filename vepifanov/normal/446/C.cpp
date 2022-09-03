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
#include <cassert>

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
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000*1000*1000+9;
const int N = 300000;
const int M = 1 << 19;

int n;
int m;
ii f[N + 1];
ii s[N + 1];
int tree[2 * M + 10];
ii add[2 * M + 10];
int x[N + 1];

ii mrg (ii a, ii b) {
    re mp ((a.fi + b.fi) % mod, (a.se + b.se) % mod);
}

int build (int x, int l, int r) {
    if (l == r) re tree[x] = ::x[l];
    int s = (l + r) / 2;
    re tree[x] = (build (x * 2 + 1, l, s) + build (x * 2 + 2, s + 1, r)) % mod;
}

ii shift (ii x, int len) {
    int a = ((ll)f[len + 1].fi * x.fi + (ll)f[len + 1].se * x.se) % mod;
    int b = ((ll)f[len + 2].fi * x.fi + (ll)f[len + 2].se * x.se) % mod;
    re mp (a, b);
}

int getsum (ii x, int len) {
    re ((ll)s[len].fi * x.fi + (ll)s[len].se * x.se) % mod;
}

int push (int x, int l, int r) {
    if (add[x].fi == 0 && add[x].se == 0) re 0;
    if (l != r) {
        int s = (l + r) / 2;
        add[x * 2 + 1] = mrg (add[x * 2 + 1], add[x]);
        add[x * 2 + 2] = mrg (add[x * 2 + 2], shift (add[x], s - l + 1));
    }
    tree[x] = (tree[x] + getsum (add[x], r - l + 1)) % mod;
    add[x] = mp (0, 0);
    re 0;
}     

int get (int x, int l, int r, int lc, int rc) {
    push (x, l, r);
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re (get (x * 2 + 1, l, s, lc, rc) + get (x * 2 + 2, s + 1, r, lc, rc)) % mod;
}       

int upd (int x, int l, int r, int lc, int rc, ii y) {
    push (x, l, r);
    if (r < lc || l > rc) re tree[x];
    if (l >= lc && r <= rc) {
        y = shift (y, l - lc);
        add[x] = mrg (add[x], y);
        push (x, l, r);
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = (upd (x * 2 + 1, l, s, lc, rc, y) + upd (x * 2 + 2, s + 1, r, lc, rc, y)) % mod;
}
                              
int main () {
    ii a (1, 0), b (0, 1), cur (1, 1);
    f[1] = a;
    f[2] = b;
    s[1] = a;
    s[2] = cur;
    for (int i = 3; i <= N; i++) {
        ii c = mrg (a, b);
        f[i] = c;
        cur = mrg (cur, c);
        s[i] = cur;
        a = b;
        b = c;
    }
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    build (0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        scanf ("%d%d%d", &t, &a, &b); a--; b--;
        if (t == 1) {
            upd (0, 0, n - 1, a, b, mp (1, 1));
        } else {
            printf ("%d\n", get (0, 0, n - 1, a, b));
        }
    }
    return 0;
}