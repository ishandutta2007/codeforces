#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()
#define int long long

int MOD = 31607;

int inv(int b, int p = MOD - 2) {
    if(p == 0) return 1;
    int x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

int inv_dem = inv(10000);

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> p(n, vector<int>(1 << n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] *= inv_dem;
            a[i][j] %= MOD;
        }
    }
    for(int i = 0; i < n; i++) {
        p[i][0] = 1;
        for(int msk = 1; msk < (1 << n); msk++) {
            for(int lst = n - 1; lst >= 0; lst--) {
                if((msk & (1 << lst))) {
                    p[i][msk] = p[i][msk ^ (1 << lst)] * a[i][lst] % MOD;
                    break;
                }
            }
        }
    }
    vector<int> dp(1 << n);
    vector<int> col(n, 1);
    vector<int> x(1 << n);
    x[0] = 1;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            col[j] *= a[i][j];
            col[j] %= MOD;
        }
    }
    for(int i = 1; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                x[i] = x[i ^ (1 << j)] * col[j];
                x[i] %= MOD;
                break;
            }
        }
    }
    for(int msk = (1 << n) - 1; msk >= 0; msk--) {
        int tmp[4];
        for(int i = 0; i < 4; i++) tmp[i] = 1;
        
        for(int i = 0; i < n; i++) {
            int nmsk = (1 << n) - 1 - msk;
            tmp[0] *= (1 - p[i][nmsk]);
            tmp[0] %= MOD;
            if(n % 2 && i == n / 2) {
                int mult = 1;
                if(!(msk & (1 << i))) {
                    nmsk -= (1 << i);
                    mult *= a[i][i];
                }
                mult %= MOD;
                tmp[3] *= (mult * (1 - p[i][nmsk])) % MOD;
                tmp[3] %= MOD;
                tmp[1] *= (mult * (1 - p[i][nmsk])) % MOD;
                tmp[2] *= (mult * (1 - p[i][nmsk])) % MOD;
                tmp[0] %= MOD, tmp[1] %= MOD, tmp[2] %= MOD, tmp[3] %= MOD;
                continue;
            }
            if(msk & (1 << i)) {
                tmp[1] *= (1 - p[i][nmsk]);
                tmp[1] %= MOD;
            }
            else {
                tmp[1] *= (a[i][i] * (1 - p[i][nmsk - (1 << i)])) % MOD;
                tmp[1] %= MOD;
            }
            if(msk & (1 << (n - 1 - i))) {
                tmp[2] *= (1 - p[i][nmsk]);
                tmp[2] %= MOD;
            }
            else {
                tmp[2] *= (a[i][n - 1 - i] * (1 - p[i][nmsk - (1 << (n - 1 - i))]) % MOD);
                tmp[2] %= MOD;
            }
            int mult = 1;
            if(!(msk & (1 << i))) {
                nmsk -= (1 << i);
                mult *= a[i][i];
                mult %= MOD;
            }
            if(!(msk & (1 << (n - 1 - i)))) {
                nmsk -= (1 << (n - 1 - i));
                mult *= a[i][n - 1 - i];
                mult %= MOD;
            }
            mult %= MOD;
            tmp[3] *= (mult * (1 - p[i][nmsk])) % MOD;
            tmp[0] %= MOD, tmp[1] %= MOD, tmp[2] %= MOD, tmp[3] %= MOD;
        }
        dp[msk] = tmp[0] - (tmp[1] + tmp[2]) + tmp[3];
        dp[msk] %= MOD;
    }
    int ans = 0;
    for(int msk = 0; msk < (1 << n); msk++) {
        if(__builtin_popcount(msk) % 2 == 0) {
            ans += dp[msk] * x[msk];
            ans %= MOD;
        }
        else {
            ans -= dp[msk] * x[msk];
            ans %= MOD;
        }
    }
    ans = 1 - ans;
    if(ans < 0) ans += MOD;
    cout << ans % MOD << "\n";
}