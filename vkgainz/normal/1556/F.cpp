#include <iostream>
#include <vector>

using namespace std;

vector<long long> all(1 << 14);
long long dp[15][1 << 14];
long long MOD = 1e9 + 7;
long long p[15][15];

long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = a[i] * inv(a[i] + a[j]) % MOD;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int msk = 0; msk < (1 << 14); msk++) {
            dp[i][msk] = 1LL;
            for (int j = 0; j < n; j++) {
                if (msk & (1 << j))
                    dp[i][msk] *= p[i][j], dp[i][msk] %= MOD;
            }
        }
    }
    all[0] = 1LL;
    for (int msk = 1; msk < (1 << n); msk++) {
        all[msk] = 1;
        for (int s = msk; s; s = (s - 1) & msk) {
            if (s == msk) continue;
            long long sub = all[s];
            long long edges = 1LL;
            for (int i = 0; i < n; i++) {
                if (s & (1 << i)) {
                    edges *= dp[i][msk ^ s];
                    edges %= MOD;
                }
            }
            all[msk] -= sub * edges % MOD;
            all[msk] %= MOD;
        }
    }
    long long ans = 0LL;
    for (int i = 0; i < n; i++) {
        //compute
        long long prob_win = 0LL;
        for (int msk = 0; msk < (1 << n); msk++) {
            if (msk & (1 << i)) {
                long long temp = all[msk];
                vector<int> c, d;
                long long edges = 1LL;
                for (int j = 0; j < n; j++) {
                    if (msk & (1 << j))
                        c.push_back(j);
                    else
                        d.push_back(j);
                }
                for (int x : c)
                    for (int y : d)
                        edges *= p[x][y], edges %= MOD;
                prob_win += temp * edges % MOD;
                prob_win %= MOD;
            }
        }
        ans += prob_win;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}