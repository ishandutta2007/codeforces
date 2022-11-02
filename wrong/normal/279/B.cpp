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

int N, T, A[100050];

int main()
{
    scanf("%d%d", &N, &T);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    int res = 0, tm = 0, start = 0;
    for (int i = 0; i < N; ++i) {
        tm += A[i];
        while (tm > T) {
            tm -= A[start];
            ++start;
        }
        chmax(res, i - start + 1);
    }

    printf("%d\n", res);

    return 0;
}