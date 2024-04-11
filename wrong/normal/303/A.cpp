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

    if (n % 2 == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << i << (i == n - 1 ? '\n' : ' ');
        }
        for (int i = 0; i < n; ++i) {
            cout << i << (i == n - 1 ? '\n' : ' ');
        }
        for (int i = 0; i < n; ++i) {
            cout << (2 * i % n) << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}