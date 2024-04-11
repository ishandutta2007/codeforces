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

#define I64 "%I64d"

typedef unsigned uint;
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const lint INF = 1001001001001001001LL;

lint dp[100050];
lint max1, max2;
int max1_pos, max2_pos;

void init(int n)
{
    for (int i = 0; i < n; ++i) {
        dp[i] = -INF;
    }
    max1 = max2 = -INF;
    max1_pos = max2_pos = -1;
}

void change(int i, lint v)
{
    if (max1_pos < 0) {
        max1_pos = i;
        max1 = v;
    } else if (max2_pos < 0) {
        if (i == max1_pos) {
            max1 = v;
        } else {
            max2_pos = i;
            max2 = v;
            if (max1 < max2) {
                swap(max1_pos, max2_pos);
                swap(max1, max2);
            }
        }
    } else {
        if (i == max1_pos) {
            max1 = v;
        } else {
            if (v > max1) {
                max2_pos = max1_pos;
                max2 = max1;
                max1_pos = i;
                max1 = v;
            } else if (v > max2) {
                max2_pos = i;
                max2 = v;
            }
        }
    }

    dp[i] = v;
}

int N, Q, C[100050];
lint V[100050];

int main()
{
    scanf("%d%d", &N, &Q);

    for (int i = 0; i < N; ++i) {
        scanf(I64, &V[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &C[i]);
        --C[i];
    }

    for (int i = 0; i < Q; ++i) {
        lint A, B;
        scanf(I64 I64, &A, &B);
        
        init(N);

        for (int j = 0; j < N; ++j) {
            lint next_v = V[j] * B;

            if (dp[C[j]] > -INF) {
                chmax(next_v, dp[C[j]] + V[j] * A);
            }

            lint other_max = max1;
            if (max1_pos == C[j]) {
                other_max = max2;
            }

            if (other_max > -INF) {
                chmax(next_v, other_max + V[j] * B);
            }

            if (next_v > dp[C[j]]) {
                change(C[j], next_v);
            }
        }

        printf(I64 "\n", max(0LL, *max_element(dp, dp + N)));
    }

    return 0;
}