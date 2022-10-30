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

int A[100050];
int incL[100050];
int incR[100050];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
        incL[i] = incR[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (A[i - 1] >= A[i]) chmax(incL[i], incL[i - 1] + 1);
    }
    for (int i = n - 1; i >= 1; --i) {
        if (A[i] <= A[i + 1]) chmax(incR[i], incR[i + 1] + 1);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);

        if (incR[l] + incL[r] >= r - l + 2) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}