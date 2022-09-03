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

ll n, m, x, y, a, b;

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int main () {
    cin >> n >> m >> x >> y >> a >> b;
    int d = gcd (a, b);
    a /= d;
    b /= d;
    int k = min (n / a, m / b);
    a *= k;
    b *= k;
    n *= 2;
    m *= 2;
    x *= 2;
    y *= 2;
    ll ax, ay, bx, by;
    ax = bx = n + 1;
    ay = by = m + 1;
    for (int p = -1; p <= 1; p++)
        for (int q = -1; q <= 1; q++) {
            ll x1 = x - a + p;
            ll y1 = y - b + q;
            ll x2 = x + a + p;
            ll y2 = y + b + q;
            if (x1 < 0) { x2 -= x1; x1 = 0; }
            if (x2 > n) { x1 -= x2 - n; x2 = n; }
            if (y1 < 0) { y2 -= y1; y1 = 0; }
            if (y2 > m) { y1 -= y2 - m; y2 = m; }
            if (x1 % 2 == 0 && y1 % 2 == 0 && mp (mp (x1, y1), mp (x2, y2)) < mp (mp (ax, ay), mp (bx, by))) {
                ax = x1;
                ay = y1;
                bx = x2;
                by = y2;
            }
        }
    cout << ax / 2 << " " << ay / 2 << " " << bx / 2 << " " << by / 2 << endl;
    return 0;
}