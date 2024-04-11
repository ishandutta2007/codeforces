#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10, mod = 1e9 + 7;
int a[maxn], vn[maxn], vp[maxn], f[maxn], c[maxn][maxn];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return a * 1ll * b % mod; }

void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            c[i][j] = c[i - 1][j];
            if (j) c[i][j] = add(c[i][j], c[i - 1][j - 1]);
        }
    }
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = mul(f[i - 1], i);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n; cin >> n;
    int nn = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) continue;
        vn[a[i]] = true; vp[i] = true;
        --nn;
    }
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vn[i] && !vp[i]) ++k;
    }
    // cout << "k = " << k << endl;
    int ans = 0, sgn = 1;
    for (int i = 0; i <= k; ++i) {
        int p = mul(c[k][i], f[nn - i]);
        if (sgn == 1) ans = add(ans, p);
        else ans = sub(ans, p);
        sgn *= -1;
    }
    cout << ans << endl;
    return 0; 
}