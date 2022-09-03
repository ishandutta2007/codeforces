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
int x, y, dx, dy, k;

int main () {
    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &x, &y); x--; y--;
    scanf ("%d", &k);
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        scanf ("%d%d", &dx, &dy);
        int t = 1e9;
        if (dx > 0) t = min (t, (n - x - 1) / dx); else
        if (dx < 0) t = min (t, x / (-dx));
        if (dy > 0) t = min (t, (m - y - 1) / dy); else
        if (dy < 0) t = min (t, y / (-dy));
        ans += t;
        x += dx * t;
        y += dy * t;
    }
    cout << ans << endl;
    return 0;
}