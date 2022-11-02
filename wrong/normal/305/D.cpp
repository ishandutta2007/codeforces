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

const int MOD = 1000000007;

int outk[1<<20];
int ok[1<<20];
int pow2[1<<20];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);

        if (v == u + 1) {
            continue;
        }
        if (v == u + k + 1) {
            outk[u] = 1;
            continue;
        }
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        outk[i] += outk[i - 1];
    }

    for (int i = 1; i <= n - k - 1; ++i) {
        if (outk[n] - outk[i + k] > 0) {
            continue;
        }
        if (outk[max(0, i - k - 1)] > 0) {
            continue;
        }
        ok[i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (!ok[i] && outk[i] - outk[i - 1] > 0) {
            cout << 0 << endl;
            return 0;
        }
        ok[i] += ok[i - 1];
    }

    pow2[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    int res = outk[n] == 0 ? 1 : 0;
    for (int i = 1; i <= n - k - 1; ++i) {
        if (ok[i] - ok[i - 1] == 0) {
            continue;
        }
        if (outk[i - 1] > 0) {
            break;
        }
        int all = ok[min(n - k - 1, i + k)] - ok[i];
        int exist = outk[min(n - k - 1, i + k)] - outk[i];
        res += pow2[all - exist];
        if (res >= MOD) {
            res -= MOD;
        }
    }

    cout << res << endl;

    return 0;
}