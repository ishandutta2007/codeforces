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

char S[1<<20];
int dp[1<<20][2];

int main()
{
    scanf("%s", S);
    int N = strlen(S);

    for (int i = 0; i <= N; ++i) {
        dp[i][0] = dp[i][1] = INF;
    }

    dp[N - 1][0] = S[N - 1] == '0' ? 0 : 1;
    dp[N - 1][1] = S[N - 1] == '0' ? 0 : 1;

    bool one = S[N - 1] == '1';
    for (int i = N - 2; i >= 0; --i) {
        if (S[i] == '1') {
            chmin(dp[i][0], dp[i + 1][0] + 1);
        } else {
            chmin(dp[i][0], dp[i + 1][0]);
            chmin(dp[i][0], dp[i + 1][1] + 1);
        }

        char f = S[i];
        if (one) {
            f = f == '0' ? '1' : '0';
        }

        if (f == '1') {
            chmin(dp[i][1], dp[i + 1][1] + 1);
        } else {
            chmin(dp[i][1], dp[i + 1][1]);
            chmin(dp[i][1], dp[i + 1][0] + 1);
        }

        if (S[i] == '1') {
            one = true;
        }
    }

    cout << min(dp[0][0], dp[0][1] + 1) << endl;

    return 0;
}