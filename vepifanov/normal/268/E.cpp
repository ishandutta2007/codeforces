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
ii v[50000];

bool l1 (ii a, ii b) {
    re a.fi * a.se * (100 - b.se) > b.fi * b.se * (100 - a.se);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d", &v[i].fi, &v[i].se);
    sort (v, v + n, l1);
    double ans = 0, cur = 0;
    for (int i = n - 1; i >= 0; i--) {
//      printf ("%d %d %.10f\n", v[i].fi, v[i].se, cur);
        ans += v[i].fi * (v[i].se / 100.0 * cur + 1);
        cur += 1 - v[i].se / 100.0;
    }
    printf ("%.6f\n", ans);
    return 0;
}