#include <bits/stdc++.h>

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
#define next NEXT
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
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const int N = 1 << 13;

int n;
int m;
vi f[2 * N];
int ct;
int t[100000];
int x[100000];
int y[100000];
int len[100000];
int dir[100000];
int res[100000];

int build (int x, int l, int r) {
//  printf ("build %d %d %d = %d\n", x, l, r, n + r - l + 1);
    f[x].resize (n + r - l + 2);
    if (l == r) re 0;
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
    re 0;
}

int build2 (int x, int l, int r) {
    memset (&f[x][0], 0, sz (f[x]) * sizeof (int));
    if (l == r) re 0;
    int s = (l + r) / 2;
    build2 (x * 2 + 1, l, s);
    build2 (x * 2 + 2, s + 1, r);
    re 0;
}

int get (int x, int t, int y) {
    if (t != ct) re 0;
    y++;
    int s = 0;
//  printf ("getf %d %d %d\n", x, t, y);
    while (y < sz (f[x])) {
        s += f[x][y];
        y |= y + 1;
    }
    re s;
}

void upd (int x, int t, int y, int z) {
    if (t != ct) re;
    y++;
//  printf ("updf %d %d = %d %d %d\n", x, t, y, z, sz (f[x]));
    assert (y < sz (f[x]));
    while (y > 0) {
        f[x][y] += z;
        y = (y & (y + 1)) - 1;
    }
}

int getf (int x, int l, int r, int xc, int yc) {
//  printf ("getf %d %d %d = %d %d %d\n", x, l, r, yc, yc - xc + r, xc + yc - l);
    re get (x, 0, yc) + get (x, 1, yc - xc + r) + get (x, 2, xc + yc - l);
}

int get (int x, int l, int r, int xc, int yc) {
    if (r < xc || l > xc) re 0;
//  printf ("%d %d %d %d %d\n", x, l, r, xc, yc);
    if (l == r) re getf (x, l, r, xc, yc);
    int s = (l + r) / 2;
    re get (x * 2 + 1, l, s, xc, yc) + get (x * 2 + 2, s + 1, r, xc, yc) + getf (x, l, r, xc, yc);
}

void upd (int x, int l, int r, int lc, int rc, int t, int y, int z) {
    if (t != ct) re;
//    printf ("%d %d %d %d %d %d %d %d\n", x, l, r, lc, rc, t, y, z);
    if (r < lc || l > rc) re;
    if (l >= lc && r <= rc) {
        if (t == 0) upd (x, t, y, z);
        if (t == 1) upd (x, t, y + r, z);
        if (t == 2) upd (x, t, y - l, z);
        re;
    }
    int s = (l + r) / 2;
    upd (x * 2 + 1, l, s, lc, rc, t, y, z);
    upd (x * 2 + 2, s + 1, r, lc, rc, t, y, z);
}

int main () {
    scanf ("%d%d", &n, &m);
    build (0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &t[i]);
        if (t[i] == 1) {
            scanf ("%d%d%d%d", &dir[i], &x[i], &y[i], &len[i]); x[i]--; y[i]--;
        } else {
            scanf ("%d%d", &x[i], &y[i]); x[i]--; y[i]--;
        }
    }
    for (ct = 0; ct < 3; ct++) {
        build2 (0, 0, n - 1);
        for (int i = 0; i < m; i++) {
            int t = ::t[i];
            if (t == 1) {
                int dir = ::dir[i], x = ::x[i], y = ::y[i], len = ::len[i];
                if (dir == 1) {
                    upd (0, 0, n - 1, x, x + len, 0, y - 1, -1);
                    upd (0, 0, n - 1, x, x + len, 2, x + y + len, 1);
                }
                if (dir == 2) {
                    upd (0, 0, n - 1, x, x + len, 0, y, 1);
                    upd (0, 0, n - 1, x, x + len, 1, y - len - x - 1, -1);
                }
                if (dir == 3) {
                    upd (0, 0, n - 1, x - len, x, 0, y - 1, -1);
                    upd (0, 0, n - 1, x - len, x, 1, y + len - x, 1);
                }
                if (dir == 4) {
                    upd (0, 0, n - 1, x - len, x, 0, y, 1);
                    upd (0, 0, n - 1, x - len, x, 2, x + y - len - 1, -1);
                }
            } else {
                int x = ::x[i], y = ::y[i];
                res[i] += get (0, 0, n - 1, x, y);
            }
        }
    }   
    for (int i = 0; i < m; i++)
        if (t[i] == 2)
            printf ("%d\n", res[i]);
    re 0;
}