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
pair<ii, int> v[10000];
int res[10000];

int dist (int x1, int y1, int x2, int y2) {
    re sqr (x2 - x1) + sqr (y2 - y1);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].fi.fi, &v[i].fi.se);
        v[i].se = i;
        res[i] = -1;
    }   
    sort (v, v + n);
    scanf ("%d", &m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int xx, yy;
        scanf ("%d%d", &xx, &yy);
        int l = 0, r = n;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (v[s].fi.fi <= xx) l = s; else r = s;
        }
        for (int j = max (0, l - 1); j < min (n, r + 2); j++)
            if (dist (v[j].fi.fi, 0, xx, yy) <= v[j].fi.se * v[j].fi.se && res[v[j].se] == -1) {
                ans++;
                res[v[j].se] = i + 1;
            }   
    }
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}