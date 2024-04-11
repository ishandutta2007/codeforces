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
    int n, k;
    cin >> n >> k;

    if (n < k) {
        cout << -1 << endl;
    } else if (k == 1) {
        if (n == 1) {
            cout << "a" << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        stringstream ss;
        n -= k - 2;

        for (int i = 0; i < n; ++i) {
            ss << "ab"[i % 2];
        }
        for (int i = 0; i < k - 2; ++i) {
            ss << (char)('c' + i);
        }

        cout << ss.str() << endl;
    }

    return 0;
}