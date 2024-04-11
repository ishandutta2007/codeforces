#include <bits/stdc++.h>

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
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const int mod = 1000*1000*1000+7;
const int N = 2*1000*1000+10;

int n;
int m;
int f[N];
int rf[N];

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int cnk (int n, int k) {
    if (n < 0 || k < 0 || n < k) re 0;
    re ((ll)f[n] * rf[k] % mod * rf[n - k]) % mod;
}

int main () {
    f[0] = rf[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = power (f[i], mod - 2);
    }
    scanf ("%d", &n);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int cur = cnk (2 * i + 1, i);
        int tmp = cnk (2 * i, i);
        ans = (ans + (ll)2 * cur - tmp) % mod;
        if (ans < 0) ans += mod;
    }
    printf ("%d\n", ans);
    re 0;
}