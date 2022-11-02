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

int a[1<<20];
Int A[1<<21];

int main()
{
    int n, l, t;
    scanf("%d%d%d", &n, &l, &t);

    Int N = n, L = l * 2, T = t * 2;
    double res = T / (L / 2) * double(N) * (N - 1) / 2 * 0.5;
    T %= L / 2;

    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        A[i] = A[N + i] = a[i] * 2;
        A[N + i] += L;
    }
    A[2 * N] = 2 * L;

    int ptr = 0;
    for (int i = 0; i < N; ++i) {
        while (A[ptr] - A[i] <= T * 2) {
            ++ptr;
        }
        res += (ptr - i - 1) / 4.0;
    }

    printf("%.9f\n", res);

    return 0;
}