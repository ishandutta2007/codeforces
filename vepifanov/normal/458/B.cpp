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
#include <cassert>

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
#define j0 j1347829
#define j1 j234892
                         
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

int x[100000];
int y[100000];

int main () {
    scanf ("%d%d", &n, &m);
    ll sx = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        sx += x[i];
    }
    ll sy = 0;
    for (int i = 0; i < m; i++) {
        scanf ("%d", &y[i]);
        sy += y[i];
    }
    sort (x, x + n);
    sort (y, y + m);
    reverse (x, x + n);
    reverse (y, y + m);
    ll ans = 4e18;
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += x[i - 1];
        if ((ans - (sx - cur)) / i < sy) continue;
        ans = min (ans, sy * i + (sx - cur));
    }
    cur = 0;
    for (int i = 1; i <= m; i++) {
        cur += y[i - 1];
        if ((ans - (sy - cur)) / i < sx) continue;
        ans = min (ans, sx * i + (sy - cur));
    }
    cout << ans << endl;
    return 0;
}