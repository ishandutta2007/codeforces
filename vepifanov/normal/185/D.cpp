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

int n;
ll k, l, r;

ll power (ll a, ll b, ll mod) {
    ll c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        b /= 2;
        a = ((ll)a * a) % mod;
    }
    re c;
}

pair<ll, ll> calc (ll x, ll r, ll mod) {
    if (r == 0) re mp (1, 1);
    if (!(r & 1)) {
        pair<ll, ll> tmp = calc (x, r - 1, mod);
        re mp ((tmp.fi * x + 1) % mod, (tmp.se * x) % mod);
    } else {
        pair<ll, ll> tmp = calc (x, r / 2, mod);
        re mp ((tmp.fi * (1 + (tmp.se * x) % mod)) % mod, ((tmp.se * tmp.se) % mod * x) % mod);
    }
}

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        ll k, l, r, p;
        scanf ("%I64d%I64d%I64d%I64d", &k, &l, &r, &p);
        int ok = k & 1;
//      k %= p;
//      if (k == 0) printf ("1\n"); else
        if (k == 1) printf ("%I64d\n", (ll)2 % p); else 
        if (p == 2) {
            if (k & 1) printf ("0\n"); else printf ("1\n");
        } else {
            k = power (k, (power (2, l, p - 1) + p - 1), p);
//          printf ("%I64d %I64d %I64d\n", k, p, power (2, l, p - 1));
            r = r - l + 1;
            ll all = calc (k, p - 2, p).fi;
            ll sum = calc (k, (power (2, r, p - 1) + p - 2) % (p - 1), p).fi;
//          printf ("%I64d %I64d %I64d %I64d\n", k, all, sum, power (2, r, p) / (p - 1));
            ll cnt = ((power (2, r, p) - power (2, r, p - 1) + p) * power (p - 1, p - 2, p)) % p;
            if (power (2, r, p - 1) == 0) sum = 0;
//          printf ("%I64d %I64d %I64d %I64d\n", cnt, all, sum, power (2, r, 1e18) / (p - 1));
            ll ans = (cnt * all + sum) % p;
            if (k == 0) ans = 1;
//          printf ("%I64d %I64d\n", ans, r - 1);
            if (ok) ans = (ans * power (power (2, p - 2, p), r - 1, p)) % p;
            printf ("%I64d\n", ans);
        }
    }
    return 0;
}