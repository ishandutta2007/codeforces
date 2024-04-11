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

int X1[5], Y1[5], X2[5], Y2[5];
int xs[30], ys[30];

int field[30][30];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        xs[2 * i + 0] = X1[i];
        xs[2 * i + 1] = X2[i];
        ys[2 * i + 0] = Y1[i];
        ys[2 * i + 1] = Y2[i];
    }
    sort(xs, xs + 2 * n);
    sort(ys, ys + 2 * n);

    int X = unique(xs, xs + 2 * n) - xs;
    int Y = unique(ys, ys + 2 * n) - ys;

    for (int i = 0; i < n; ++i) {
        X1[i] = lower_bound(xs, xs + X, X1[i]) - xs;
        Y1[i] = lower_bound(ys, ys + Y, Y1[i]) - ys;
        X2[i] = lower_bound(xs, xs + X, X2[i]) - xs;
        Y2[i] = lower_bound(ys, ys + Y, Y2[i]) - ys;
        X1[i] *= 2; Y1[i] *= 2; X2[i] *= 2; Y2[i] *= 2;
    }

    memset(field, 0, sizeof(field));
    int minx = 100, miny = 100, maxx = -1, maxy = -1;
    for (int i = 0; i < n; ++i) {
        for (int x = X1[i]; x <= X2[i]; ++x) {
            for (int y = Y1[i]; y <= Y2[i]; ++y) {
                field[x][y] = 1;
                chmin(minx, x); chmin(miny, y);
                chmax(maxx, x); chmax(maxy, y);
            }
        }
    }

    bool ok = (xs[maxx / 2] - xs[minx / 2]) == (ys[maxy / 2] - ys[miny / 2]);
    for (int x = minx; x <= maxx; ++x) {
        for (int y = miny; y <= maxy; ++y) {
            ok &= field[x][y];
        }
    }

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}