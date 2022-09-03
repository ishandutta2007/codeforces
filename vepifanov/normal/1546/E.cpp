#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int mod = 998244353;
 
int n;
int m;
set<int> u[500][500];
int g[1000][500];
int bad[1000];

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                u[i][j].clear ();
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < n; j++) {
                scanf ("%d", &g[i][j]);
                g[i][j]--;
                u[j][g[i][j]].insert (i);
            }
        int ans = 1;
        vi res;
        memset (bad, 0, sizeof (bad));
        for (int t = 0; t < n; t++) {
            int now = -1;
            for (int i = 0; i < n && now == -1; i++) 
                for (int j = 0; j < n; j++)
                    if (sz (u[i][j]) == 1) {
                        now = *u[i][j].begin ();
                        break;
                    }
            if (now == -1) {
                for (int i = 0; i < 2 * n; i++)
                    if (!bad[i]) {
                        now = i;
                        break;
                    }
                ans = (ans * 2) % mod;
            }
            res.pb (now + 1);
            vi rem;
            for (int i = 0; i < n; i++)
                for (auto x : u[i][g[now][i]])
                    if (!bad[x]) {
                        rem.pb (x);
                        bad[x] = 1;
                    }
            for (auto x : rem)
                for (int i = 0; i < n; i++)
                    u[i][g[x][i]].erase (x);
        }
        printf ("%d\n", ans);
        for (auto x : res) printf ("%d ", x);
        printf ("\n");
    }
    re 0;
}