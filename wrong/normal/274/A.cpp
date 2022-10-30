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

int a[100050];

int main()
{
    int n, k;

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int res = 0;
    set<Int> forbid;

    for (int i = 0; i < n; ++i) {
        if (forbid.find(a[i]) != forbid.end()) {
            continue;
        }
        ++res;
        forbid.insert((Int)k * a[i]);
    }

    printf("%d\n", res);

    return 0;
}