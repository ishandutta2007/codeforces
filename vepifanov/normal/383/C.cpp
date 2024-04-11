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

const int N = 1 << 18;

int n;
int m;
int tree[2][2 * N + 10];
vi v[200000];
int p[200000];
int f[200000];
int d[200000];
int x[200000];
int o;

int go (int x, int p, int l) {
    d[x] = l;
    ::p[x] = o;
    o++;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p)
            go (v[x][i], x, 1 - l);
    f[x] = o - 1;
    re 0;
}

int upd (int t, int x, int l, int r, int lc, int rc, int z) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) {
        tree[t][x] += z;
        re 0;
    }   
    int s = (l + r) / 2;
    upd (t, x * 2 + 1, l, s, lc, rc, z);
    upd (t, x * 2 + 2, s + 1, r, lc, rc, z);
    re 0;
}

int get (int t, int x, int l, int r, int y) {
    if (r < y || l > y) re 0;
    if (l == r) re tree[t][x];
    int s = (l + r) / 2;
    re get (t, x * 2 + 1, l, s, y) + get (t, x * 2 + 2, s + 1, r, y) + tree[t][x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    go (0, 0, 0);
    for (int i = 0; i < m; i++) {   
        int t;
        scanf ("%d", &t);
        if (t == 1) {
            int a, b;
            scanf ("%d%d", &a, &b); a--;
            upd (d[a], 0, 0, n - 1, p[a], f[a], b);
            upd (1 - d[a], 0, 0, n - 1, p[a], f[a], -b);
        } else {
            int a;
            scanf ("%d", &a); a--;
            printf ("%d\n", get (d[a], 0, 0, n - 1, p[a]) + x[a]);
        }
    }
    return 0;
}