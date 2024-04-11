#include <bits/stdc++.h>
using namespace std;

int mod;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

typedef pair<pair<int, int>, pair<int, int>> mat;
#define x first
#define y second

mat matmul(const mat& a, const mat& b) {
    mat ret;
    ret.x.x = add(mul(a.x.x, b.x.x), mul(a.x.y, b.y.x));
    ret.x.y = add(mul(a.x.x, b.x.y), mul(a.x.y, b.y.y));
    ret.y.x = add(mul(a.y.x, b.x.x), mul(a.y.y, b.y.x));
    ret.y.y = add(mul(a.y.x, b.x.y), mul(a.y.y, b.y.y));
    return ret;
}

int fib(long long n) {
    n -= 2;
    mat t = make_pair(make_pair(1, 1), make_pair(1, 0));
    mat a = make_pair(make_pair(1, 0), make_pair(0, 1));
    for (; n; n >>= 1) {
        if (n & 1) a = matmul(a, t);
        t = matmul(t, t);
    }
    return add(mul(a.x.x, 3), mul(a.y.x, 2));
}

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    long long n, k; int l; cin >> n >> k >> l >> mod;
    if (mod == 1) return cout << "0" << endl, 0;
    if (l < 63 && (1ll << l) <= k) return cout << "0" << endl, 0;
    int ans = 1;
    int f = fib(n);
    for (int i = 0; i < min(l, 63); ++i) {
        if ((1ll << i) & k) ans = mul(ans, sub(fpow(2, n), f));
        else ans = mul(ans, f);
    }
    if (l >= 63) {
        for (int i = 0; i < l - 63; ++i) ans = mul(ans, f);
    }
    cout << ans << endl;
    return 0;
}