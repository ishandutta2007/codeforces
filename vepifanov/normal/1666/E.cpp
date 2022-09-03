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
int x[100100];
int res[100100];
pair<ll, ll> u[100100];

int can (int l, int r, bool get_res = false) {
//    printf ("can %d %d\n", l, r);
    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (get_res) u[i] = mp (a, b);
        b = min (b, (ll)x[i]);
//        printf ("%d %d\n", a, b);
        if (a > b) re 0;
        a += l;
        b += r;
        a = max (a, (ll)x[i]);
        if (a > b) re 0;
    }
//    printf ("%d %d\n", a, b);
    if (get_res) {
        u[n + 1] = mp (a, b);
        res[n + 1] = m;
        for (int i = n; i > 0; i--) {
            ll na = res[i + 1] - r;
            ll nb = res[i + 1] - l;
            na = max (na, u[i].fi);
            nb = min (nb, u[i].se);
            assert (na <= nb);
            res[i] = na;
        }
        re 0;
    } else re int (a <= m && b >= m);
}

int main () {
    scanf ("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) scanf ("%d", &x[i]);
    x[0] = 0;
    x[n + 1] = m;
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        int ok = 0;
        ll top = -1e18;
        for (int i = 0; i <= n + 1 && !ok; i++) {
            if (x[i] - (ll)s * i + s < top) ok = 1;
            if (i > 0) top = max (top, x[i - 1] - (ll)s * (i - 1));
        }
        if (ok) r = s; else l = s;
    }
    int low = l;
    l = low, r = m + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (low, s)) r = s; else l = s;
    }
 //   printf ("%d %d\n", low, r);
    can (low, r, true);
    for (int i = 1; i <= n; i++) printf ("%d %d\n", res[i], res[i + 1]);
    re 0;
}