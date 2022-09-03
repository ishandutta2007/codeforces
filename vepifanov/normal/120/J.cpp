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

typedef pair<ii, ii> iiii;
typedef vector<iiii> viiii;

const int COEF = 1;
const int CNT = 50;

int n;
int m;
int ans;

viiii v;
ii i1, i2;

bool l1 (iiii a, iiii b) {
    re a.fi.se < b.fi.se || a.fi.se == b.fi.se && a.fi.fi < b.fi.fi || a.fi.se == b.fi.se && a.fi.fi == b.fi.fi && a.se < b.se;
}

int dist (ii a, ii b) {
    re sqr (a.fi - b.fi) + sqr (a.se - b.se);
}

int go (viiii v) {
    int n = sz (v);
    if (n < 20) {
        for (int i = 0; i < sz (v); i++)
            for (int j = i + 1; j < sz (v); j++)
                if (v[i].se.fi != v[j].se.fi) {
                    int tmp = dist (v[i].fi, v[j].fi);
                    if (tmp < ans) {
                        ans = tmp;
                        i1 = v[i].se;
                        i2 = v[j].se;
                    }
                }
        re 0;
    }
    int s = n / 2;
    viiii v1, v2, w;
    for (int i = 0; i < s; i++) v1.pb (v[i]);
    for (int i = s; i < n; i++) v2.pb (v[i]);
    go (v1);
    go (v2);
    int xs = v[s].fi.fi;
    for (int i = 0; i < n; i++)
        if (sqr (xs - v[i].fi.fi) <= COEF * ans)
            w.pb (v[i]);
    sort (all (w), l1);
    for (int i = 0; i < sz (w); i++)
        for (int j = max (0, i - CNT); j <= min (sz (w) - 1, i + CNT); j++)
            if (w[i].se.fi != w[j].se.fi) {
                int tmp = dist (w[i].fi, w[j].fi);
                if (tmp < ans) {
                    ans = tmp;
                    i1 = w[i].se;
                    i2 = w[j].se;
                }
            }
    re 0;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        v.pb (mp (mp (x, y), mp (i + 1, 1)));
        if (x != 0) v.pb (mp (mp (-x, y), mp (i + 1, 2)));
        if (y != 0) v.pb (mp (mp (x, -y), mp (i + 1, 3)));
        if (x != 0 && y != 0) v.pb (mp (mp (-x, -y), mp (i + 1, 4)));
    }
    sort (all (v));
    ans = 1e9;
    go (v);
    printf ("%d %d %d %d\n", i1.fi, 5 - i1.se, i2.fi, i2.se);
    return 0;
}