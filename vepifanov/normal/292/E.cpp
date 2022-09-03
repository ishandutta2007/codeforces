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
int tree[1 << 19];
int full[1 << 19];
int x[100000];
int y[100000];
int a[100001];
int b[100001];

int get (int x, int l, int r, int y) {
    if (full[x] || l == r) re tree[x];
    int s = (l + r) / 2;
    if (y <= s) re get (x * 2 + 1, l, s, y);
    re get (x * 2 + 2, s + 1, r, y);
}

int put (int x, int l, int r, int lc, int rc, int y) {
    if (r < lc || l > rc) re 0;
    if (l >= lc && r <= rc) {
        full[x] = 1;
        tree[x] = y;
        re 0;
    }
    int s = (l + r) / 2;
    if (full[x]) {
        full[x] = 0;
        full[x * 2 + 1] = full[x * 2 + 2] = 1;
        tree[x * 2 + 1] = tree[x * 2 + 2] = tree[x];
    }
    put (x * 2 + 1, l, s, lc, rc, y);
    put (x * 2 + 2, s + 1, r, lc, rc, y);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
    memset (tree, 0, sizeof (tree));
    memset (full, 0, sizeof (full));
    for (int i = 1; i <= m; i++) {
        int t, a, b, c;
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d%d%d", &a, &b, &c); a--; b--;
            ::a[i] = a;
            ::b[i] = b;
                        put (0, 0, n - 1, b, b + c - 1, i);
        } else {
            scanf ("%d", &c); c--;
            int tmp = get (0, 0, n - 1, c);
            if (tmp == 0) printf ("%d\n", y[c]); else printf ("%d\n", x[c - ::b[tmp] + ::a[tmp]]);
        }
    }
    return 0;
}