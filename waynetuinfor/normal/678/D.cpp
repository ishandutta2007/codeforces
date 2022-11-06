#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, long long b) { return (long long)a * (long long)b % mod; }

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    int a, b, x; long long n; cin >> a >> b >> n >> x;
    int ca = fpow(a, n);
    int cbd, cbn, cb;
    if (a != 1) {
        cbd = fpow(sub(a, 1), mod - 2);
        cbn = mul(a, sub(fpow(a, n - 1), 1));
        cb = mul(b, add(mul(cbd, cbn), 1));
    } else cb = mul(b, mul(a, n));
    cout << add(mul(ca, x), cb) << endl;
    return 0;
}