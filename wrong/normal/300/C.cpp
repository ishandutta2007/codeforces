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

Int pow(Int x, Int e)
{
    Int v = 1;
    for (; e; e >>= 1, x = (x*x) % MOD) { 
        if (e & 1) {
            v = (v*x) % MOD;
        }
    }
    return v;
}
Int inv(Int x)
{
    return pow(x, MOD-2);
}

Int fac[1<<20], facinv[1<<20];

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    fac[0] = facinv[0] = 1;
    for (int i = 1; i < 1<<20; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
        facinv[i] = (facinv[i - 1] * inv(i)) % MOD;
    }

    Int res = 0;
    for (int as = 0; as <= n; ++as) {
        int sum = as * a + (n - as) * b;
        bool exc = true;
        while (sum > 0) {
            exc &= sum%10 == a || sum%10 == b;
            sum /= 10;
        }
        if (exc) {
            (res += fac[n] * facinv[as] % MOD * facinv[n-as] % MOD) %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}