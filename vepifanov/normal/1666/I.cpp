// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int inf = 1e9 + 100;

int n;
int m;
vector<pair<ii, int> > v;

int ask (int x, int y) {
    printf ("SCAN %d %d\n", x, y);
    fflush (stdout);
    int z;
    scanf ("%d", &z);
    v.pb (mp (mp (x, y), z));
    re z;
}

int dist (int x1, int y1, int x2, int y2) {
    re abs (x2 - x1) + abs (y2 - y1);
}

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        v.clear ();
        scanf ("%d%d", &n, &m);
        int a = ask (1, 1); // (x1 - 1) + (y1 - 1) + (x2 - 1) + (y2 - 1)
        int b = ask (n, 1); // (n - x1) + (y1 - 1) + (n - x2) + (y2 - 1)
        int bb =  2 * m + 2 * n - b - 4; // (x1 - 1) + (m - y1) + (x2 - 1) + (m - y2)
        int sy = (a + b - 2 * n + 6) / 2;
        int sx = (a + bb - 2 * m + 6) / 2;
        int c = ask (sx / 2, 1);
        int d = ask (1, sy / 2);
        vector<pair<ii, ii> > w;
        for (int x1 = 1; x1 <= n; x1++)
            for (int y1 = 1; y1 <= m; y1++)
                for (int x2 = 1; x2 <= n; x2++)
                    for (int y2 = 1; y2 <= m; y2++) {
                        if (mp (x1, y1) >= mp (x2, y2)) continue;
                        int ok = 1;
                        for (int i = 0; i < sz (v); i++)
                            ok &= int (dist (x1, y1, v[i].fi.fi, v[i].fi.se) + dist (x2, y2, v[i].fi.fi, v[i].fi.se) == v[i].se);
                        if (ok) w.pb (mp (mp (x1, y1), mp (x2, y2)));
                    }
//        for (auto &t : w) printf ("%d %d %d %d\n", t.fi.fi, t.fi.se, t.se.fi, t.se.se);
//        assert (sz (w) == 1);
        for (int i = 0; i < sz (w); i++) {
            printf ("DIG %d %d\n", w[i].fi.fi, w[i].fi.se);
            fflush (stdout);
            int res;
            scanf ("%d", &res);
            if (res == 0) continue;
            printf ("DIG %d %d\n", w[i].se.fi, w[i].se.se);
            fflush (stdout);
            scanf ("%d", &res);
            assert (res == 1);
            break;
        }
    }
    re 0;
}