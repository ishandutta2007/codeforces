#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
        re x > 0 ? x : -x;
}


int n;
int m;

ll x[100000], y[100000];

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; }

ll can (ll k) {
    ll h = k * m;
    ll res = 1;
    int i = 1;
    ll cnk = 1;
    while (h > 0 && res < n && i <= m && i <= k) {
        if (cnk < n) {
            cnk *= (k - i + 1);
            cnk /= i;
            if (cnk > n) cnk = n;
        }
        ll tmp = cnk;
        if (i > 0) tmp = min (tmp, h / i);
        h -= tmp * i;
        res += tmp;
        i++;
    }
    re res;
}

int main() {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d%d", &n, &m);
        ll l = -1, r = 2e9;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (can (s) >= n) r = s; else l = s;
        }
        printf ("%I64d\n", r);
    }
        return 0;
}