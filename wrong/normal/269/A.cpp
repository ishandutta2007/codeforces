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

const int INF = 1001001001;
const lint INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int main()
{
    int n;
    lint sol = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int k, a;
        scanf("%d%d", &k, &a);

        lint e = 1, f = 4;

        while (a > f) {
            ++e;
            f *= 4;
        }

        chmax(sol, k + e);
    }

    cout << sol << endl;

    return 0;
}