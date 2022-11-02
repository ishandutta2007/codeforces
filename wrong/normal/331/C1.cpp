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

int dp[1<<20];

int main()
{
    dp[0] = 0;

    for (int i = 1; i < 1<<20; ++i) {
        dp[i] = INF;
        for (int j = i; j > 0; j /= 10) {
            chmin(dp[i], dp[i - j % 10] + 1);
        }
    }

    int n;
    cin >> n;

    cout << dp[n] << endl;

    return 0;
}