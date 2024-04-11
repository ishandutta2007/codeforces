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

    Int tm = 0, que = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;

        que -= min(que, t - tm);
        tm = t;
        que += c;
        chmax(mx, que);
    }

    if (que > 0) {
        tm += que;
    }

    cout << tm << ' ' << mx << endl;

    return 0;
}