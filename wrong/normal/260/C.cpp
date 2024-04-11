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
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int n, x, a[100050];
lint res[100050];

int relative_pos(int y)
{
    return (x - y + n) % n;
}

int main()
{
    cin >> n >> x;
    --x;

    int minv = 1001001001, minp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (minv > a[i] || (minv == a[i] && relative_pos(minp) > relative_pos(i))) {
            minv = a[i];
            minp = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == minp) {
            res[i] = (lint)minv * n + relative_pos(i);
        } else {
            res[i] = a[i] - minv - (relative_pos(i) <= relative_pos(minp)? 1 : 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == n-1) {
            cout << res[i] << endl;
        } else {
            cout << res[i] << ' ';
        }
    }

    return 0;
}