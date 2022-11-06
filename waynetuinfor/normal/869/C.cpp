#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, mod = 998244353;
long long c[maxn][maxn], f[maxn];

void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j <= i; ++j) {
            c[i][j] = c[i - 1][j];
            if (j) c[i][j] += c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = f[i - 1] * i % mod;
}

long long go(int a, int b) {
    long long ret = 0;
    for (int i = 0; i <= min(a, b); ++i) ret += c[a][i] * c[b][i] % mod * f[i] % mod, ret %= mod;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int a, b, c; cin >> a >> b >> c;
    long long ans = 1ll;
    ans *= go(a, b); ans %= mod;
    ans *= go(b, c); ans %= mod;
    ans *= go(c, a); ans %= mod;
    cout << ans << endl;
    return 0;
}