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
int x[3];
int y[3];
vi vx;
vi vy;
int p[9];
set<ii> all;

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int main () {
    for (int i = 0; i < 3; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        vx.pb (x[i]);
        vy.pb (y[i]);
        all.insert(mp (x[i], y[i]));
    }
    sort (all (vx));
    sort (all (vy));
    vx.resize (unique (all (vx)) - vx.begin ());
    vy.resize (unique (all (vy)) - vy.begin ());
    n = sz (vx);
    m = sz (vy);
    ll ans = 1e18;
    vector<pair<ii, ii> > best;
    for (int mask = 1; mask < (1 << (n * m)); mask++) {
        vii u;
        int orig = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((mask >> (i * m + j)) & 1) {
                    u.pb (mp (vx[i], vy[j]));
                    if (all.count (u.back ())) orig++;
                }
        if (orig < 3) continue;
        vector<pair<int, ii> > w;
        for (int i = 0; i < sz (u); i++)
            for (int j = i + 1; j < sz (u); j++)
                if (u[i].fi == u[j].fi || u[i].se == u[j].se)
                    w.pb (mp (abs (u[i].fi - u[j].fi) + abs (u[i].se - u[j].se), mp (i, j)));
        sort (all (w));
        for (int i = 0; i < sz (u); i++) p[i] = i;
        int rem = sz (u);
        ll cur = 0;
        vector<pair<ii, ii> > now;
        for (int i = 0; i < sz (w); i++) {
            int a = gp (w[i].se.fi);
            int b = gp (w[i].se.se);
            if (a != b) {
                rem--;
                p[a] = b;
                cur += w[i].fi;
                now.pb (mp (u[w[i].se.fi], u[w[i].se.se]));
            }
        }
        if (rem > 1) continue;
        if (cur < ans) {
            ans = cur;
            best = now;
        }
    }
    printf ("%d\n", sz (best));
    for (auto& x : best) printf ("%d %d %d %d\n", x.fi.fi, x.fi.se, x.se.fi, x.se.se);
    re 0;
}