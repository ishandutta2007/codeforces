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

int E[5000000];

int main()
{
    int n, P[3050];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }

    int inv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (P[i] > P[j]) {
                ++inv;
            }
        }
    }

    if (inv == 0) {
        cout << 0 << endl;
        return 0;
    }

    --inv;
    E[0] = 0;
    E[1] = 3;
    for (int i = 2; i <= inv; ++i) {
        E[i] = 4 + E[i - 2];
    }

    cout << E[inv] + 1 << endl;

    return 0;
}