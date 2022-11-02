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

Int A[200050];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    Int sum = 0, on = n;
    for (int i = 1, j = 1; j <= on; ++j) {
        Int sub = (n - i) * A[j];
        if (i > 1 && (sum / (i - 1) - sub < k / (i - 1) || sum - sub * (i - 1) < k)) {
            cout << j << endl;
            --n;
            continue;
        }
        sum += A[j] * (i - 1);
        ++i;
    }

    return 0;
}