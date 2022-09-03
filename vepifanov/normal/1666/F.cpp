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
const int mod = 998244353;
const int N = 5000;

int n;
int m;
int res[N + 1][N + 1];
int cnk[N + 1][N + 1];
int x[N];

int main () {
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j % i == 0)
                cnk[i][j] = 1;
            else
                cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
        sort (x, x + n);
        reverse (x, x + n);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
                res[i][j] = 0;
        if (x[0] == x[1]) {
            printf ("0\n");
            continue;
        }
        res[1][1] = 1;
        for (int i = 1; i < n; ) {
            int k = 0;
            while (i + k < n && x[i + k] == x[i]) k++;
            for (int j = 1; j <= i; j++) {
                int rem = j - 1 + int (j == n / 2) - (i - j);
                if (k <= rem) res[i + k][j] = (res[i + k][j] + (ll)res[i][j] * cnk[rem][k]) % mod;
                if (i + k < n && k - 1 <= rem) res[i + k][j + 1] = (res[i + k][j + 1] + (ll)res[i][j] * cnk[rem][k - 1]) % mod;
            }
            i += k;
        }
        printf ("%d\n", res[n][n / 2]);
    }
    re 0;
}