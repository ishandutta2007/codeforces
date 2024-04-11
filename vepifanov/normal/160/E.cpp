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

int s[100000], f[100000], res[100000], t[100000], b[100000], l[100000], r[100000];
ii tree[600000];
vi v;
map<int, int> num;
vector<pair<ii, int> > w;

ii add (int x, int l, int r, int p, ii q) {
    if (r < p || l > p) re tree[x];
    if (l == r) re tree[x] = q;
    int s = (l + r) / 2;
    re tree[x] = max (add (x * 2 + 1, l, s, p, q), add (x * 2 + 2, s + 1, r, p, q));
}

ii get (int x, int l, int r, int lc, int rc, int q) {
    if (r < lc || l > rc || tree[x].fi < q) re mp (0, 0);
    if (l == r) re tree[x];
    int s = (l + r) / 2;
    ii tmp = get (x * 2 + 1, l, s, lc, rc, q);
    if (tmp.fi >= q) re tmp;
    tmp = get (x * 2 + 2, s + 1, r, lc, rc, q);
    if (tmp.fi >= q) re tmp;
    re mp (0, 0);
}


int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d", &s[i], &f[i], &t[i]);
        v.pb (t[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &l[i], &r[i], &b[i]);
        v.pb (b[i]);
    }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    for (int i = 0; i < sz (v); i++) num[v[i]] = i;
    int k = sz (v);
    for (int i = 0; i < n; i++) {
        t[i] = num[t[i]];
        w.pb (mp (mp (s[i], 0), i));
    }
    for (int i = 0; i < m; i++) {
        b[i] = num[b[i]];
        w.pb (mp (mp (l[i], 1), i));
    }
    sort (all (w));
    for (int i = 0; i < sz (w); i++) {
        int j = w[i].se;
        if (w[i].fi.se == 0) {  
//          printf ("add %d = %d %d\n", t[j], f[j], j + 1);
            add (0, 0, k - 1, t[j], mp (f[j], j + 2));
        } else {
            res[j] = get (0, 0, k - 1, b[j], k - 1, r[j]).se - 1;
//          printf ("get %d %d = %d\n", b[j], r[j], res[j]);
        }
    }   
    for (int i = 0; i < m; i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}