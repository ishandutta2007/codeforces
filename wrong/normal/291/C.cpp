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

uint P[100050], Q[100050];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        uint a, b, c, d;
        scanf("%u.%u.%u.%u", &a, &b, &c, &d);
        P[i] = ((a * 256 + b) * 256 + c) * 256 + d;
    }

    for (int ones = 1; ones < 32; ++ones) {
        uint mask = ((1u << ones) - 1) << (32 - ones);
        for (int i = 0; i < n; ++i) {
            Q[i] = P[i] & mask;
        }
        sort(Q, Q + n);
        if (unique(Q, Q + n) - Q == k) {
            printf("%u.%u.%u.%u\n", mask >> 24, (mask >> 16) & 255, (mask >> 8) & 255, mask & 255);
            return 0;
        }
    }

    puts("-1");

    return 0;
}