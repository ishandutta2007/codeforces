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

const int N = 1 << 16;

struct matr {
    int a, b, c, d;
};

int n;
int m;
ll K;
int mod;
matr tree[2 * N];
int s[N];
pair<ll, int> v[N];
matr full;

matr mul (matr x, matr y) {
    matr z;
    z.a = ((ll)x.a * y.a + (ll)x.b * y.c) % mod;
    z.b = ((ll)x.a * y.b + (ll)x.b * y.d) % mod;
    z.c = ((ll)x.c * y.a + (ll)x.d * y.c) % mod;
    z.d = ((ll)x.c * y.b + (ll)x.d * y.d) % mod;
    re z;
}

matr build (int x, int l, int r) {
    if (l == r) re tree[x] = {0, s[l], 1, s[l]};
    int s = (l + r) / 2;
    re tree[x] = mul (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
}

matr get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re {1, 0, 0, 1};
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re mul (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

matr power (matr a, ll b) {
    matr c = {1, 0, 0, 1};
    while (b) {
        if (b & 1) c = mul (c, a);
        a = mul (a, a);
        b /= 2;
    }
    re c;
}

matr skip (ll a, ll b) {
    if (a > b) re {1, 0, 0, 1};
    ll na = a / n;
    ll nb = b / n;
    ll ma = a % n;
    ll mb = b % n;
//  printf ("%I64d %I64d = %I64d %I64d = %I64d %I64d\n", a, b, na, nb, ma, mb);
    if (na == nb) re get (0, 0, n - 1, ma, mb);
    re mul (mul (get (0, 0, n - 1, ma, n - 1), power (full, nb - na - 1)), get (0, 0, n - 1, 0, mb));
}

int main () {
    scanf ("%I64d%d", &K, &mod);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &s[i]);
    build (0, 0, n - 1);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf ("%I64d%d", &v[i].fi, &v[i].se);
    }   
    sort (v, v + m);
    matr cur = {1, 0, 0, 1};
    full = get (0, 0, n - 1, 0, n - 1);
    ll last = 0;
    K--;
    for (int i = 0; i < m; i++) {
        if (v[i].fi > K) {
            cur = mul (cur, skip (last, K));
            last = K + 1;
            break;
        } else {
            cur = mul (cur, skip (last, v[i].fi - 1));
            cur = mul (cur, {0, v[i].se, 1, v[i].se});
            last = v[i].fi + 1;
        }
    }
    cur = mul (cur, skip (last, K));
    int ans = ((ll)cur.c + cur.d - cur.a - cur.b) % mod;
    if (ans < 0) ans += mod;
    printf ("%d\n", ans);
    return 0;
}