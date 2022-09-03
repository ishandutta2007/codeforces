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
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int m, mod;
ll n;
ll a, b, c, d;

int go (ll x, ll f, ll d, ll n) {
    if (x > b || x + n - 1 < a) re 0;
    if (x >= a && x + n - 1 <= b) {
        ll p = c, q = ::d;
        if (p < f) p = f; else 
        if ((p - f) % d != 0) p = ((p - f) / d + 1) * d + f;
        if (q > f + d * (n - 1)) q = f + d * (n - 1);
        if (q < p) re 0;
        q = (q - f) / d * d + f;
        ll tmp = 0;
        ll t = (q - p) / d + 1;
        if (t & 1) {
            tmp = p % mod;
            t--;
            p += d;
        }
        t /= 2;
        if (p <= q) tmp = (tmp + ((p + q) % mod) * (t % mod)) % mod;
        re tmp;
    }
    re (go (x, f, d * 2, (n + 1) / 2) + go (x + (n + 1) / 2, f + d, d * 2, n / 2)) % mod;
}

int main () {
    scanf ("%I64d%d%d", &n, &m, &mod);
    for (int i = 0; i < m; i++) {
        scanf ("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
        printf ("%d\n", go (1, 1, 1, n) % mod);
    }
    return 0;
}