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

int N, A[100050];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    Int lo = 0, hi = 1001001001001LL;
    while (hi - lo > 1) {
        Int mid = (hi + lo) / 2;
        Int rem = 0;
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (mid < A[i]) {
                ok = false;
            } else {
                rem += -(A[i] - mid);
            }
        }
        if (ok && rem >= mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << endl;

    return 0;
}