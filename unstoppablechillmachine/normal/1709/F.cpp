#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int mod = 998244353;
const int H = 16;
const int N = 2e5 + 10;
int dp[H][N]; //size at least n with height = h

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int bin_pow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return mul(a, bin_pow(a, b - 1));
    }
    return bin_pow(mul(a, a), b >> 1);
}

const int maxN = 1e6 + 10;
int psq[maxN];

void init() {
    int s = 31;
    for (int i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
        if (i < maxN) psq[i] = s;
    }
}

void fft(vector<int> &s, vector<int> &res, int n, int x, int ss = 0, int step = 1, int rs = 0) {
    if (n == 1) {
        res[rs] = s[ss];
        return;
    }
    fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
    fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
    int c = 1;
    for (int i = rs; i < rs + n / 2; ++i) {
        auto a = res[i], b = res[i + n / 2];
        res[i] = mul(b, c);
        add(res[i], a);
        res[i + n / 2] = a;
        sub(res[i + n / 2], mul(b, c));
        c = mul(c, x);
    }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector<int> as(a.begin(), a.end()), bs(b.begin(), b.end());
    int n = 1;
    while (n < a.size() || n < b.size()) n *= 2;
    n *= 2;
    as.resize(n);
    bs.resize(n);
    int t = psq[n];
    vector<int> resa(n), resb(n);
    fft(as, resa, n, t);
    fft(bs, resb, n, t);
    for (int i = 0; i < n; i++) {
        resa[i] = mul(resa[i], resb[i]);
    }
    t = bin_pow(t, mod - 2);
    fft(resa, as, n, t);
    int rn = bin_pow(n, mod - 2);
    for (int i = 0; i < n; i++) {
        as[i] = mul(as[i], rn);
    }
    return as;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    init();
    int n, k, f;
    cin >> n >> k >> f;
    for (int i = 0; i <= k; i++) {
        dp[1][i] = k - i + 1;
    }
    for (int h = 2; h <= n; h++) {
        vector<int> A(k + 1), B(k + 1);
        for (int i = 0; i <= k; i++) {
            A[i] = dp[h - 1][i];
            sub(A[i], dp[h - 1][i + 1]);
            B[i] = dp[h - 1][i];
        }
        /*for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                add(C[i], mul(A[j], B[i - j]));
            }
        }*/
        auto C = multiply(A, B);
        for (int i = 0; i <= k; i++) {
            dp[h][i] = mul(dp[h - 1][0], dp[h - 1][i + 1]);
            add(dp[h][i], C[i]);
            dp[h][i] = mul(dp[h][i], k - i + 1);
        }
    }
    int answer = 0;
    for (int i = 0; i <= min(k, f); i++) {
        int kek1 = dp[n][i];
        sub(kek1, dp[n][i + 1]);
        int kek2 = dp[n][f - i];
        sub(kek2, dp[n][f - i + 1]);
        add(answer, mul(kek1, kek2));
    }
    cout << answer << '\n';
    return 0;
}