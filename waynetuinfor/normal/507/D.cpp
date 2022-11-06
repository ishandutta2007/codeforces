#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxk = 100 + 10;
int dp[2][maxn][maxk], n, k, m, p[maxn], pp[maxn];
bool v[2][maxn][maxk];

inline int add(int a, int b, int mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b, int mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, int mod) { return a * 1ll * b % mod; }

inline int get(int n) { return n < 0 ? 0 : pp[n]; }

int go(int now, int r, int nz) {
    if (now == n && r == 0 && nz) return 1;
    if (r == 0 && nz) return mul(9, get(n - now - 1), m);
    if (now == n || (r == 0 && nz)) return 0;
    if (v[nz][now][r]) return dp[nz][now][r];
    v[nz][now][r] = true;
    dp[nz][now][r] = 0;
    for (int dig = 0; dig < 10; ++dig) {
        dp[nz][now][r] = add(dp[nz][now][r], go(now + 1, add(r, mul(p[now], dig, k), k), (nz || (dig != 0))), m);
    }
    return dp[nz][now][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    p[0] = 1; pp[0] = 1;
    for (int i = 1; i < maxn; ++i) p[i] = mul(p[i - 1], 10, k);
    for (int i = 1; i < maxn; ++i) pp[i] = mul(pp[i - 1], 10, m);
    cout << go(0, 0, 0) << endl;
    return 0;
}