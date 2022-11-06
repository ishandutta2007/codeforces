#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> coef; coef.push_back(1);
    for (int i = 1; i <= n; ++i) {
        int s = 0; size_t ptr = 0;
        for (int j = i; j >= 1; --j) s = add(s, mul(a[j], coef[ptr++]));
        cout << s << ' ';
        coef.push_back(mul(coef.back(), mul(k + i - 1, fpow(i, mod - 2))));
    }
    return 0;
}