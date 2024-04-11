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

int main()
{
    int n, A[111];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A, A+n);

    cout << 1 << ' ' << A[0] << endl;
    if (A[n-1] > 0) {
        cout << 1 << ' ' << A[n-1] << endl;
        cout << n-2 << ' '; pv(A+1, A+n-1);
    } else {
        cout << 2 << ' ' << A[1] << ' ' << A[2] << endl;
        cout << n-3 << ' '; pv(A+3, A+n);
    }

    return 0;
}