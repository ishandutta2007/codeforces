#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, m; cin >> n >> m;
    int s = 0, inv2 = fpow(2, mod - 2);
    vector<long long> vec;
    for (long long t = 1; t < n; t = (n / (n / (t + 1)))) vec.push_back(t);
    vec.push_back(n);
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    reverse(vec.begin(), vec.end());
    for (long long t : vec) {
        long long r = min(m, n / t), l = n / (t + 1);
        l = min(l, r - 1);
        int sum = mul((l + 1 + r) % mod, (r - l) % mod);
        sum = mul(sum, inv2);
        s = add(s, mul(t % mod, sum));
        if (r == m) break;
    }
    int ans = mul(n % mod, m % mod); ans = sub(ans, s);
    cout << ans << endl;
    return 0;
}