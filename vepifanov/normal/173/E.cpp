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
int m, k, K;
ii r[200000], a[200000];
int f[200001];
int ak[200001];
int ai[200001];
int res[200000];
int R[200000];
int A[200000];
int ans[200000];
int tree[600000];
vector<pair<ii, ii> > v;

int FIND (int x) {
    if (ak[0] > x) re -1;
    int l = 0, r = k;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (ak[s] <= x) l = s; else r = s;
    }
    re l;
}

int FIND2 (int x) {
    if (ak[0] >= x) re 0;
    int l = 0, r = k;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (ak[s] < x) l = s; else r = s;
    }
    re r;
}

int FIND3 (int x) {
    if (ak[k - 1] <= x) re k;
    int l = -1, r = k - 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (ak[s] > x) r = s; else l = s;
    }
    re l;
}

int add (int x, int p) {
    x++;
//  printf ("add %d\n", x);
    while (x <= k) {
        f[x] += p;
        x |= x + 1;
    }
    re 0;
}

int get (int x) {
    x = FIND (x) + 1;
    int y = 0;
    while (x > 0) {
        y += f[x];
        x = (x & (x + 1)) - 1;
    }
    re y;
}

int add2 (int x, int l, int r, int p, int q) {
    if (r < p || l > p) re tree[x];
    if (l == r) re tree[x] = max (tree[x], q);
    int s = (l + r) / 2;
    re tree[x] = max (add2 (x * 2 + 1, l, s, p, q), add2 (x * 2 + 2, s + 1, r, p, q));
}

int get2 (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re max (get2 (x * 2 + 1, l, s, lc, rc), get2 (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    scanf ("%d%d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &r[i].fi);
        R[i] = r[i].fi;
        r[i].se = i;
    }
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i].fi);
        A[i] = a[i].fi;
        a[i].se = i;
    }
    sort (r, r + n);
    sort (a, a + n);
    k = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].fi != a[i - 1].fi) k++;
        ak[k] = a[i].fi;
        ai[a[i].se] = k;
    }
    k++;
    memset (f, 0, sizeof (f));
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && r[j].fi == r[i].fi) {
            add (ai[r[j].se], 1);
            j++;
        }   
        for (int t = i; t < j; t++)
            res[r[t].se] = get (A[r[t].se] + K) - get (A[r[t].se] - K - 1);
        i = j;
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y); x--; y--;
        if (R[x] < R[y]) swap (x, y);
        v.pb (mp (mp (R[x], i), mp (x, y)));
    }
    sort (all (v));
    reverse (all (v));
    int j = n - 1;
    memset (tree, 0, sizeof (tree));
    for (int i = 0; i < m; i++) {
        int x = v[i].se.fi;
        int y = v[i].se.se;
//      cerr << j << endl;
        while (j >= 0 && r[j].fi >= R[x]) {
            add2 (0, 0, k - 1, ai[r[j].se], res[r[j].se]);
            j--;
        }
//      printf ("%d %d\n", x, y);
        int l = max (A[x], A[y]) - K;
        int r = min (A[x], A[y]) + K;
//      cerr << x + 1 << " " << y + 1 << " " << l << " " << r << " " << ak[2] << endl;
        int ll = FIND2 (l);
        int rr = FIND3 (r);
//      cerr << ll << " " << rr << endl;
        int tmp = 0;
        if (ll <= rr) tmp = get2 (0, 0, k - 1, ll, rr);
        if (tmp == 0) tmp = -1;
        ans[v[i].fi.se] = tmp;
    }
    for (int i = 0; i < m; i++) printf ("%d\n", ans[i]);
    return 0;
}