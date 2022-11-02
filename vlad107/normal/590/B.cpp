#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = -1;
const int INF = 1e9 + 19;

int main() {
    // freopen("input.txt", "r", stdin);
    double x1, y1, x2, y2, vmax, t, vx, vy, wx, wy;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;
    double ll = 0, rr = 1e10;
    for (int it = 0; it < 10000; it++) {
        double tt = (ll + rr) * 0.5;
        double t1, t2;
        if (tt > t) t1 = t, t2 = tt - t; 
        else t1 = tt, t2 = 0;
        // cerr << t1 << " " << t2 << endl;
        double xx = x1 + t1 * vx + t2 * wx;
        double yy = y1 + t1 * vy + t2 * wy;
        // cerr << xx << " " << yy << endl;
        double dst = (x2 - xx) * (x2 - xx) + (y2 - yy) * (y2 - yy);
        double can = vmax * tt;
        // cerr << dst << " " << can << endl;
        if (dst > can * can) {
            ll = tt;
        } else {
            rr = tt;
        }
    }
    printf("%.17lf\n", ll);
    return 0;
}