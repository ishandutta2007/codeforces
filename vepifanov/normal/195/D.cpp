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
int m;
vector<pair<ii, ii> > v;
vector<pair<ll, ll> > res;

bool l1 (pair<ii, ii> a, pair<ii, ii> b) {
    re (ll)a.fi.fi * b.fi.se < (ll)b.fi.fi * a.fi.se;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int k, b;
        scanf ("%d%d", &k, &b);
        if (k < 0) {
            v.pb (mp (mp (-2e9, 1), mp (k, b)));
            v.pb (mp (mp (b, -k), mp (-k, -b)));
        } else
        if (k > 0) {
            v.pb (mp (mp (-b, k), mp (k, b)));
            v.pb (mp (mp (2e9, 1), mp (-k, -b)));
        }
    }
    v.pb (mp (mp (-2e9, 1), mp (0, 0)));
    v.pb (mp (mp (2e9, 1), mp (0, 0)));
    sort (all (v), l1);
    ll sk = 0, sb = 0;
    for (int i = 0; i + 1 < sz (v); i++) {
        sk += v[i].se.fi;
        sb += v[i].se.se;
        if (l1 (v[i], v[i + 1])) res.pb (mp (sk, sb));
    }
    int ans = 0;
    for (int i = 0; i + 1 < sz (res); i++)
        ans += int (res[i] != res[i + 1]);
    printf ("%d\n", ans);
    return 0;
}