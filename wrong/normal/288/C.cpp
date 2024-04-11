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

int used[1<<20], res[1<<20];

int main()
{
    int n;
    Int sum = 0;
    scanf("%d", &n);

    memset(res, ~0, sizeof(res));
    for (int mask = (1<<22)-1; mask > 0; mask >>= 1) {
        for (int i = 0; i <= n; ++i) {
            int inv = (i ^ mask) & mask;
            if (~res[i]) {
                continue;
            }
            if (0 <= inv && inv <= n && !used[inv]) {
                res[i] = inv;
                sum += i ^ inv;
                used[inv] = 1;
            }
        }
    }
    if (!~res[0]) {
        res[0] = 0;
    }

    printf("%I64d\n", sum);
    for (int i = 0; i <= n; ++i) {
        printf("%d%c", res[i], i == n ? '\n' : ' ');
    }

    return 0;
}