#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

Int gcd(Int m, Int n)
{
    return n ? gcd(n, m % n) : m;
}

int main()
{
    Int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;

    Int g = gcd(a, b);
    a /= g;
    b /= g;

    Int lo = 1, hi = INF;
    while (hi - lo > 1) {
        Int mid = (hi + lo) / 2;
        Int xl = a * mid, yl = b * mid;

        if (xl <= n && yl <= m) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    double cx = x, cy = y;
    chmin(cx, n - a * lo / 2.0); chmax(cx, a * lo / 2.0);
    chmin(cy, m - b * lo / 2.0); chmax(cy, b * lo / 2.0);

    Int ax = (Int)(cx - a * lo / 2.0), ay = (Int)(cy - b * lo / 2.0);
    Int bestdis = INFLL * 8;
    vector<Int> best;

    for (Int dx = -5; dx <= 5; ++dx) {
        for (Int dy = -5; dy <= 5; ++dy) {
            Int x1 = ax + dx, y1 = ay + dy;
            if (x1 < 0 || x1 > n || y1 < 0 || y1 > m) {
                continue;
            }

            Int x2 = x1 + a * lo, y2 = y1 + b * lo;
            if (x2 < 0 || x2 > n || y2 < 0 || y2 > m) {
                continue;
            }

            if (!(x1 <= x && x <= x2 && y1 <= y && y <= y2)) {
                continue;
            }

            Int dx2 = 2 * x - (x2 + x1);
            Int dy2 = 2 * y - (y2 + y1);
            Int dis = dx2*dx2 + dy2*dy2;
            vector<Int> coords;
            coords.push_back(x1);
            coords.push_back(y1);
            coords.push_back(x2);
            coords.push_back(y2);

            if (bestdis > dis || (bestdis == dis && coords < best)) {
                bestdis = dis;
                best = coords;
            }
        }
    }

    cout << best[0] << ' ' << best[1] << ' ' << best[2] << ' ' << best[3] << endl;

    return 0;
}