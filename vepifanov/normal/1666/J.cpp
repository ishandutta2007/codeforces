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
int g[210][210];
ll sum[210];
ll seg[210][210];
ll res[210][210];
int prev[210][210];
int ans[210];

int out (int i, int j) {
    if (i > j) re -1;
    if (i == j) re i;
    int x = prev[i][j];
    int a = out (i, x - 1);
    int b = out (x + 1, j);
    if (a != -1) ans[a] = x;
    if (b != -1) ans[b] = x;
    re x;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 1; i <= n; i++) {
        res[i][i] = 0;
        res[i][i - 1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        for (int j = 1; j <= n; j++)
            sum[i] += g[i][j];
    }
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = i; j <= n; j++) {
            cur += sum[j];
            for (int k = i; k < j; k++)
                cur -= g[j][k] + g[k][j];
            seg[i][j] = cur;
        }
    }
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++) {
            res[i][j] = 1e18;
            for (int k = i; k <= j; k++) {
                ll cur = res[i][k - 1] + res[k + 1][j] + seg[i][k - 1] + seg[k + 1][j];
                if (cur < res[i][j]) {
                    res[i][j] = cur;
                    prev[i][j] = k;
                }
            }
        }
    fprintf (stderr, "%lld\n", res[1][n]);
    out (1, n);
    for (int i = 1; i <= n; i++) printf ("%d ", ans[i]);
    printf ("\n");
    re 0;
}