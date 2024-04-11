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

const Int MOD = 1000000007;

int n, k, to[10];

int search(int u)
{
    if (u == k) {
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            int v[10] = {};
            bool ok2 = false;
            for (int w = i; !v[w]; w = to[w]) {
                ok2 |= w == 0;
                v[w] = 1;
                if (ok2) {
                    break;
                }
            }
            ok &= ok2;
            if (!ok) {
                break;
            }
        }
        return ok ? 1 : 0;
    }

    int res = 0;
    for (int i = 0; i < k; ++i) {
        if (u != 0 && u == i) {
            continue;
        }
        to[u] = i;
        res += search(u + 1);
    }
    return res;
}

int main()
{
    cin >> n >> k;

    Int res = 1;
    for (int i = 0; i < n - k; ++i) {
        (res *= n - k) %= MOD;
    }

    (res *= search(0)) %= MOD;

    cout << res << endl;

    return 0;
}