#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
int a, b, p;
long long x;

inline int add(int a, int b) { return (a += b) >= p ? (a - p) : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? (a + p) : a; }
inline int mul(int a, int b) { return a * 1ll * b % p; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> p >> x;
    int phi = p - 1, anow = 1;
    long long ans = 0;
    for (int i = 1; i <= phi; ++i) {
        anow = mul(anow, a);
        int bnow = mul(b, fpow(anow, p - 2));
        int d = mul(sub(bnow, i), fpow(phi, p - 2));
        long long ub = (x - i) / phi - d;
        if (ub < 0 || x - i < 0) continue;
        ans += (ub / p) + 1;
    }
    cout << ans << endl;
    return 0;
}