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
ll m;
pair<ll, int> v[100001];
int f[100002];
int x[100000];

int get (int x) {
    x++;
    int s = 0;
    while (x > 0) {
        s += f[x];
        x = (x & (x + 1)) - 1;
        }
        re s;
}

int add (int x) {
    x++;
    while (x <= n + 1) {
        f[x]++;
        x |= x + 1;
    }
    re 0;
}

ll calc (ll h) {
    if (h > 0) {
        memset (f, 0, sizeof (f));
        int k = n + 1;
        ll res = 0;
        for (int i = n; i >= 0; i--) {
            while (k - 1 > i && v[k - 1].fi - v[i].fi >= h) {
                k--;
                add (v[k].se);
            }
            res += get (v[i].se);
        }
        re res;
    } else {
        ll tmp = (ll)n * (n + 1) / 2;
        memset (f, 0, sizeof (f));
        int k = n + 1;
        ll res = 0;
        for (int i = n; i >= 0; i--) {
            while (k - 1 > i && v[k - 1].fi - v[i].fi > -h) {
                k--;
                add (n - v[k].se);
            }
            res += get (n - v[i].se);
        }
        re tmp - res;
    }   
}

int main () {
    scanf ("%d%I64d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    v[n] = mp (0, n);
    for (int i = n - 1; i >= 0; i--) v[i] = mp (v[i + 1].fi + x[i], i);
    sort (v, v + n + 1);
    ll l = -1e18, r = 1e18;
    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (calc (s) >= m) l = s; else r = s;
    }
    printf ("%I64d\n", l);
    return 0;
}