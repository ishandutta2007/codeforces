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
int s;
int p[200000];
int q[200000];
int was[200000];
vi ax;
vi ay;
vi v[200000];

int go (int x) {
    was[x] = 1;
    for (auto y : v[x])
        if (!was[y]) {
            if (x == s) q[y] = y; else q[y] = q[x];
            p[y] = x;
            if (go (y)) re 1;
        } else
        if (was[y] == 2) {
            if (q[y] != q[x]) {
                ax.clear ();
                ay.clear ();
                {
                    int i = y;
                    while (true) {
                        ax.pb (i);
                        if (i == s) break;
                        i = p[i];
                    }
                    reverse (all (ax));
                }
                {
                    int i = x;
                    ay.pb (y);
                    while (true) {
                        ay.pb (i);
                        if (i == s) break;
                        i = p[i];
                    }
                    reverse (all (ay));
                }
                re 1;
            }
        }
    was[x] = 2;
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &s); s--;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
    }
    q[s] = s;
    if (go (s)) {
        printf ("Possible\n");
        printf ("%d\n", sz (ax));
        for (int i = 0; i < sz (ax); i++) printf ("%d ", ax[i] + 1);
        printf ("\n");
        printf ("%d\n", sz (ay));
        for (int i = 0; i < sz (ay); i++) printf ("%d ", ay[i] + 1);
        printf ("\n");
    } else printf ("Impossible\n");
    re 0;
}