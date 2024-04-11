#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int mod = 998244353;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int b_pow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return mul(b_pow(a, b - 1), a);
    }
    return b_pow(mul(a, a), b >> 1);
}

const int K = 2010;
int dp[K][K], inv_f[K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    inv_f[0] = 1;
    for (int i = 1; i < K; i++) {
        inv_f[i] = mul(inv_f[i - 1], b_pow(i, mod - 2));
    }
    dp[1][1] = 1;
    for (int i = 1; i + 1 < K; i++) {
        for (int j = 1; j <= i; j++) {
            add(dp[i + 1][j], mul(dp[i][j], j));
            add(dp[i + 1][j + 1], mul(dp[i][j], j + 1));
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> pw_inv_m(k + 1);
        pw_inv_m[0] = 1;
        int inv_m = b_pow(m, mod - 2);
        for (int i = 1; i <= k; i++) {
            pw_inv_m[i] = mul(pw_inv_m[i - 1], inv_m);
        }
        vector<int> pw_half_m(k + 1);
        pw_half_m[0] = 1;
        int half_m = (m + 1) / 2;
        for (int i = 1; i <= k; i++) {
            pw_half_m[i] = mul(pw_half_m[i - 1], half_m);
        }
        vector<int> suf(k + 1);
        suf[1] = n % mod;
        for (int i = 2; i <= k; i++) {
            suf[i] = mul(suf[i - 1], n - i + 1);
        }
        int answer = 0;
        for (int i = 1; i <= min(n, k); i++) {
            int c_n_i = mul(suf[i], inv_f[i]);
            add(answer, mul(c_n_i, mul(dp[k][i], mul(pw_half_m[i], pw_inv_m[i]))));
        }
        cout << mul(answer, b_pow(m, n)) << '\n';
    }
    return 0;
}