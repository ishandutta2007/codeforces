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

const int mod = 1000*1000*1000+7;

const int N = 200000;
 
int n;
int m;
int f[N + 1];
int rf[N + 1];
int inv[N + 1];

int cnk (int n, int k) {
    if (n < 0 || k < 0 || k > n) re 0;
    re ((ll)f[n] * rf[k] % mod * rf[n - k]) % mod;
}

int main () {
    f[0] = rf[0] = f[1] = rf[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (mod - (ll)(mod / i) * inv[mod % i] % mod);
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = ((ll)rf[i - 1] * inv[i]) % mod;
    }
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        int l, r;
        scanf ("%d%d%d", &n, &l, &r);
        int ans = 0;
        int tot = min (1 - l, r - n);
        if (tot > 0) {
            if (n % 2 == 0) ans = cnk (n, n / 2); else ans = (2 * cnk (n, n / 2)) % mod;
            ans = ((ll)ans * tot) % mod;
        }
//        printf ("%d\n", tot);
        for (int i = tot + 1; ; i++) {
            int a = min (n, max (0, r - i));
            int b = min (n, max (0, n - i - l + 1));
            if (a < n / 2 || b < n / 2 || a + b < n) break;
            int c = a + b - n;
            if (n % 2 == 1) {
                ans = (ans + cnk (c, n / 2 - (a - c))) % mod;
                ans = (ans + cnk (c, (n + 1) / 2 - (a - c))) % mod;
            } else {
                ans = (ans + cnk (c, n / 2 - (a - c))) % mod;
            }
//            printf ("%d: %d %d %d %d\n", i, a, b, c, ans);
        }
        printf ("%d\n", ans);
    }
    re 0;
}