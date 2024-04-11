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

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int x[1500];
int y[1500];
int r[1500];
vector<pair<pair<ii, int>, pair<ii, int> > > v;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf ("%d%d%d%d", &x1, &y1, &x2, &y2); x1 *= 2; y1 *= 2; x2 *= 2; y2 *= 2;
        int d = gcd (abs (x2 - x1), abs (y2 - y1));
        int dx = (x2 - x1) / d, dy = (y2 - y1) / d;
        if (dx < 0 || dx == 0 && dy < 0) {
            dx = -dx;
            dy = -dy;
        }
        if (mp (x1, y1) < mp (x2, y2)) {
            v.pb (mp (mp (mp (dx, dy), x1 * dy - y1 * dx), mp (mp (x1, y1), 0)));
            v.pb (mp (mp (mp (dx, dy), x1 * dy - y1 * dx), mp (mp (x2, y2), 2)));
        } else {
            v.pb (mp (mp (mp (dx, dy), x1 * dy - y1 * dx), mp (mp (x1, y1), 2)));
            v.pb (mp (mp (mp (dx, dy), x1 * dy - y1 * dx), mp (mp (x2, y2), 0)));
        }
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &x[i], &y[i], &r[i]);
        x[i] *= 2;
        y[i] *= 2;
        r[i] *= 2;
    }
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (r[i] == r[j]) {
                ll l = sqr ((ll)(x[j] - x[i])) + sqr ((ll)(y[j] - y[i]));
                if (l <= (ll)4 * r[i] * r[i]) continue;
                int xc = (x[i] + x[j]) / 2;
                int yc = (y[i] + y[j]) / 2;
                int dx = y[j] - y[i];
                int dy = x[i] - x[j];
                int d = gcd (abs (dx), abs (dy));
                dx /= d;
                dy /= d;
                if (dx < 0 || dx == 0 && dy < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                v.pb (mp (mp (mp (dx, dy), xc * dy - yc * dx), mp (mp (xc, yc), 1)));
            }
    sort (all (v));
    ll ans = 0; 
    int cur = 0;
    for (int i = 0; i < sz (v); i++)
        if (v[i].se.se == 0)
            cur++;
        else
        if (v[i].se.se == 2)    
            cur--;
        else
            ans += cur; 
    cout << ans << endl;
    return 0;
}