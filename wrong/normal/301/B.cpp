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

int n, d;
int a[111], x[111], y[111], rem[111], vis[111];

bool ok(int first)
{
    for (int i = 0; i < n; ++i) {
        rem[i] = -1;
        vis[i] = 0;
    }

    rem[0] = first;
    while (true) {
        int next = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && (next == -1 || rem[next] < rem[i])) {
                if (rem[i] >= 0) {
                    next = i;
                }
            }
        }
        if (next < 0) {
            break;
        }
        vis[next] = 1;
        if (next == n - 1) {
            return true;
        }
        for (int i = 0; i < n; ++i) {
            if (i == next) {
                continue;
            }
            int dist = abs(x[i] - x[next]) + abs(y[i] - y[next]);
            if (d * dist > rem[next]) {
                continue;
            }
            chmax(rem[i], rem[next] - d * dist + a[i]);
        }
    }

    return false;
}

int main()
{
    cin >> n >> d;

    a[0] = a[n - 1] = 0;
    for (int i = 1; i < n - 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int lo = 0, hi = INF;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << endl;

    return 0;
}