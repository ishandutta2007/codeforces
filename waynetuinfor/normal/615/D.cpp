#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
int p[maxn], cnt[maxn];

int fpow(int, long long);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i], ++cnt[p[i]];
    int ans = 1, d = 1;
    for (int i = 1; i < maxn; ++i) if (cnt[i]) {
        long long pr = (long long)(cnt[i] + 1) * (long long)cnt[i] / 2;
        int f = fpow(i, pr);
        ans = (long long)fpow(ans, cnt[i] + 1) * (long long)fpow(f, d) % mod;
        d = (long long)d * (long long)(cnt[i] + 1) % (mod - 1);
    }
    cout << ans << endl;
    return 0;
}

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = (long long)ret * (long long)a % mod;
        a = (long long)a * (long long)a % mod;
    }
    return ret;
}