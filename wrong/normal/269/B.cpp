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

const int INF = 1001001001;
const lint INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int n, m, t[5050], dp[5050];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        double x;

        cin >> t[i] >> x;

        dp[i] = 1;

        for (int j = 0; j < i; ++j) {
            if (t[i] >= t[j]) {
                chmax(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp, dp + n) << endl;

    return 0;
}