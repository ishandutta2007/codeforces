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

int N, A[100050], dp[100050];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    if (A[0] == 1) {
        dp[1] = 1;
    }

    for (int i = 0; i < N; ++i) {
        int prs[256], pc = 0;
        for (int j = 2; j * j <= A[i]; ++j) {
            if (A[i] % j == 0) {
                while (A[i] % j == 0) {
                    A[i] /= j;
                }
                prs[pc++] = j;
            }
        }
        if (A[i] > 1) {
            prs[pc++] = A[i];
        }

        int val = 0;
        for (int j = 0; j < pc; ++j) {
            chmax(val, dp[prs[j]] + 1);
        }
        for (int j = 0; j < pc; ++j) {
            chmax(dp[prs[j]], val);
        }
    }

    printf("%d\n", *max_element(dp, dp + 100050));

    return 0;
}