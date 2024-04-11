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

int main()
{
    int n;
    cin >> n;

    int a[200];
    for (int i = 0; i < 2 * n - 1; ++i) {
        cin >> a[i];
    }

    sort(a, a + 2 * n - 1);
    int res = -INF;

    for (int i = 0; i < 2 * n; ++i) {
        if (n % 2 == 0 && i % 2 == 1) {
            continue;
        }
        int val = 0;
        for (int j = 0; j < 2 * n - 1; ++j) {
            val += a[j] * (j < i ? -1 : 1);
        }
        chmax(res, val);
    }

    cout << res << endl;

    return 0;
}