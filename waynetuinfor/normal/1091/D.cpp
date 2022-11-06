#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;
int fc[maxn], inv[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

void solve() {
    vector<int> v;
    for (int i = 1; i <= 4; ++i) v.push_back(i);
    vector<int> ans;
    do {
        for (int i : v) ans.push_back(i);
    } while (next_permutation(v.begin(), v.end()));
    for (int i = 3; i < (int)ans.size() - 1; ++i) {
        int sum = 0;
        for (int j = i - 3; j <= i; ++j) sum += ans[j];
        if ((i - 3) % 4 == 0) continue;
        if (sum == 4 * 5 / 2) {
            printf("%d: ", (i - 3) % 4);
            for (int j = i - 3; j <= i; ++j) cout << ans[j] << ' ';
            cout << endl;
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    int ans = 1;
    for (int i = 2; i <= n; ++i) ans = ans * 1ll * i % mod;
    fc[0] = 1, inv[0] = 1;
    for (int i = 1; i <= n; ++i) fc[i] = fc[i - 1] * 1ll * i % mod;
    for (int i = 1; i <= n; ++i) inv[i] = fpow(fc[i], mod - 2);
    for (int i = 2; i < n; ++i) {
        int c = fc[n] * 1ll * inv[i] % mod * inv[n - i] % mod;
        ans += c * 1ll * fc[i] % mod * fc[n - i] % mod;
        ans %= mod;
        ans += mod - c * 1ll * fc[n - i] % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
}