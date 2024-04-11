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
const int N = 100000;
 
int n;
int m;
char h[N + 1];
int f[N + 1];
int rf[N + 1];
int inv[N + 1];

int main () {
    f[0] = rf[0] = f[1] = rf[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = mod - (ll)(mod / i) * inv[mod % i] % mod;
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = ((ll)rf[i - 1] * inv[i]) % mod;
    }
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d %s", &n, h);
        int tot = n, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && h[i] == '1' && h[i + 1] == '1') {
                cnt++;
                i++;
            } else
            if (h[i] == '1') tot--;
        }
        int ans = ((ll)f[tot - cnt] * rf[cnt] % mod * rf[tot - 2 * cnt]) % mod;
        printf ("%d\n", ans);
    }
    re 0;
}