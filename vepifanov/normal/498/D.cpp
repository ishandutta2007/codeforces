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

const int N = 1 << 17;

int n;
int m;

ii tree[2 * N + 10][60];
ii y[60];
ii cur[60];
int p[100000];
         
int calc (int x, int y) {
    int p = ::p[y];
    for (int k = 0; k < 60; k++)
        if (k % p == 0)
            tree[x][k] = mp (2, (k + 2) % 60);
        else
            tree[x][k] = mp (1, (k + 1) % 60);
    re 0;
}

int merge (ii *x, ii *a, ii *b) {
    for (int k = 0; k < 60; k++)
        y[k] = mp (a[k].fi + b[a[k].se].fi, b[a[k].se].se);
    for (int k = 0; k < 60; k++)
        x[k] = y[k];
    re 0;   
}

int build (int x, int l, int r) {
    if (l == r) {
        calc (x, l);
        re 0;
    }
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
    merge (tree[x], tree[x * 2 + 1], tree[x * 2 + 2]);
    re 0;
}

int upd (int x, int l, int r, int y, int z) {
    if (r < y || l > y) re 0;
    if (l == r) {
        p[y] = z;
        calc (x, y);
        re 0;
    }
    int s = (l + r) / 2;
    upd (x * 2 + 1, l, s, y, z);
    upd (x * 2 + 2, s + 1, r, y, z);
    merge (tree[x], tree[x * 2 + 1], tree[x * 2 + 2]);
    re 0;
}

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) {
        merge (cur, cur, tree[x]);
        re 0;
    }
    int s = (l + r) / 2;
    get (x * 2 + 1, l, s, lc, rc);
    get (x * 2 + 2, s + 1, r, lc, rc);
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    build (0, 0, n - 1);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        char h[5];
        int a, b;
        scanf (" %s%d%d", h, &a, &b);
        if (h[0] == 'A') {
            for (int j = 0; j < 60; j++)
                cur[j] = mp (0, j);
            get (0, 0, n - 1, a - 1, b - 2);
            printf ("%d\n", cur[0].fi);
        } else {
            upd (0, 0, n - 1, a - 1, b);
        }

    }
    return 0;
}