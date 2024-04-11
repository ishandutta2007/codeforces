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

const int N = 200000;

int n;
int m;
vi v[N];
vi w[N];
int p, q;

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int gcd2(int a, int b, int& c, int& d) {
    if (b == 0) {
        c = 1;
        d = 0;
        return 1;
    }
    int e, f;
    int g = gcd2 (b, a % b, e, f);
    d = e - (a / b) * f;
    c = f;
    re g;
}

int power (int a, int b, int mod) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int rev(int a, int mod) {
    int x, y;
    gcd2 (a, mod, x, y);
    return (x % mod + mod) % mod;
}

set<int> all;

ll go (int r, int n, int m) {
    if (n == 1) {
        if (!v[r].empty ()) re -1;
        ll ans = 1e18;
        for (int i = 0; i < sz (v[r]); i++)
            ans = min (ans, (ll)v[r][i]);
        for (int i = 0; i < sz (w[r]); i++)
            ans = min (ans, (ll)w[r][i]);
        re ans;
    }
    int rm = rev (m % n, n);
    vii u;
    all.clear ();
    for (int i = 0; i < sz (v[r]); i++) {
        all.insert (((ll)v[r][i] * rm) % n);
        u.pb (mp (((ll)v[r][i] * rm) % n, v[r][i]));
    }
    for (int i = 0; i < sz (w[r]); i++)
        u.pb (mp (((ll)w[r][i] * rm) % n, w[r][i]));
    sort (all (u));
    vii h;
    for (int i = 0; i < sz (u); i++)
        if (i == 0 || (i > 0 && u[i].fi != u[i - 1].fi))
            h.pb (u[i]);
    ll ans = -1;
    h.pb (mp (h[0].fi + n, h[0].se));
    for (int i = 0; i + 1 < sz (h); i++)
        h[i + 1].se = min ((ll)h[i + 1].se, h[i].se + (ll)(h[i + 1].fi - h[i].fi) * m);
    h[0].se = h[sz (h) - 1].se;
    for (int i = 0; i + 1 < sz (h); i++) {
//      printf ("%d = %d %d\n", h[i].fi, h[i].se, all.count (h[i].fi));
        h[i + 1].se = min ((ll)h[i + 1].se, h[i].se + (ll)(h[i + 1].fi - h[i].fi) * m);
        if (h[i + 1].fi > h[i].fi + 1 || !all.count (h[i].fi))
            ans = max (ans, h[i].se + (ll)(h[i + 1].fi - h[i].fi - 1) * m);
    }
//  cout << ans << endl;
    re ans;
}

int main () {
    scanf ("%d%d", &n, &m);
    int g = gcd (n, m);
    if (g > N) {
        printf ("-1\n");
        re 0;
    }
    scanf ("%d", &p);
    for (int i = 0; i < p; i++) {
        int x;
        scanf ("%d", &x);
        v[x % g].pb (x / g);
    }
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf ("%d", &x);
        w[x % g].pb (x / g);
    }
    ll ans = 0;
    for (int i = 0; i < g; i++) {
        if (v[i].empty () && w[i].empty ()) {
            printf ("-1\n");
            re 0;
        }
        ll tmp = go (i, n / g, m / g);
        swap (v[i], w[i]);
        tmp = max (tmp, go (i, m / g, n / g));
        ans = max (ans, tmp * g + i);
    }
    cout << ans << endl;
    return 0;
}