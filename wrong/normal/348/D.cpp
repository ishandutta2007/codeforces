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

int N, M;
char F[3030][3030];
int dp[3030][3030];

const int MOD = 1000000007;

int paths(int r1, int c1, int r2, int c2)
{
    memset(dp, 0, sizeof(dp));
    for (int r = r1; r <= r2; ++r) {
        for (int c = c1; c <= c2; ++c) {
            if (r == r1 && c == c1) {
                dp[r][c] = F[r][c] == '#' ? 0 : 1;
            } else {
                dp[r][c] = F[r][c] == '#' ? 0 : (dp[r-1][c] + dp[r][c-1]);
            }
            dp[r][c] %= MOD;
        }
    }
    return dp[r2][c2];
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", &F[i][1]);
    }

    Int A = paths(1, 2, N-1, M), B = paths(1, 2, N, M-1);
    Int C = paths(2, 1, N-1, M), D = paths(2, 1, N, M-1);

    cout << ((A*D - B*C) % MOD + MOD) % MOD << endl;

    return 0;
}