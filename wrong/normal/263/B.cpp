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

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int main()
{
    int n, k, a[50];

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    int m = n, p = 0;
    while (p < n && m > k) {
        int q = p;

        while (q < n && a[q] == a[p]) {
            ++q;
        }
        m -= q - p;
        p = q;
    }

    if (m == k) {
        cout << a[p] << " " << a[p] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}