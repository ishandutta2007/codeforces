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

ii v[100000], w[100000];
int x, y;
vii res;

int main () {
    scanf ("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i + 1;
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d", &w[i].fi);
        w[i].se = i + 1;
    }
    sort (v, v + n);
    sort (w, w + m);
    int p = 0, q = 0;
    while (p < n && q < m)
        if (w[q].fi >= v[p].fi - x && w[q].fi <= v[p].fi + y) {
            res.pb (mp (v[p].se, w[q].se));
            p++; q++;
        } else
        if (w[q].fi < v[p].fi - x) q++; else
        if (w[q].fi > v[p].fi + y) p++;
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}