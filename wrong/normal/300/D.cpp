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

const Int MOD = 7340033;
int dp[35][1024];

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i < 35; ++i) {
        Int mul[5][1024] = {{}};
        for (int k = 0; k < 1024; ++k) {
            mul[0][0] = 1;
        }
        for (int x = 0; x < 4; ++x) {
            for (int k = 1023; k >= 0; --k) {
                for (int kk = 0; k + kk < 1024; ++kk) {
                    mul[x + 1][k + kk] += (mul[x][k] % MOD) * (dp[i - 1][kk] % MOD) % MOD;
                    if (mul[x + 1][k + kk] >= MOD) {
                        mul[x + 1][k + kk] -= MOD;
                    }
                }
            }
        }
        dp[i][0] = 1;
        for (int k = 1; k < 1024; ++k) {
            dp[i][k] = mul[4][k - 1];
        }
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; ++i) {
        int n, k;
        scanf("%d%d", &n, &k);

        int cnt = 0;
        while (true) {
            if (n % 2 == 0 || n <= 1) {
                break;
            }
            n >>= 1;
            ++cnt;
        }

        printf("%d\n", dp[cnt][k]);
    }

    return 0;
}