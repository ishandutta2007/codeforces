#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const long long inf = 1e18;
int v[maxn], o[maxn], n;
long long dp[3][maxn];
bool p[40000], ok[maxn];
vector<int> prime;

void sieve() {
    for (int i = 2; i < 32000; ++i) {
        if (!p[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < 32000; ++j) {
            p[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

bool check(int t)  {
    return (v[1] % t == 0 || v[n] % t == 0 || (v[1] + 1) % t == 0 || (v[1] - 1) % t == 0 || (v[n] + 1) % t == 0 || (v[n] - 1) % t == 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> n >> a >> b;
    int m = 0, g = 0;;
    for (int i = 1; i <= n; ++i) cin >> v[i], g = __gcd(g, v[i]), m = max(m, v[i]);
    if (g > 1) return cout << 0 << endl, 0;
    sieve();
    long long ans = inf;
    prime.push_back(v[1]); prime.push_back(v[1] + 1); prime.push_back(v[1] - 1); prime.push_back(v[n]); prime.push_back(v[n] + 1); prime.push_back(v[n] - 1);
    for (int i : prime) if (i <= m && i > 1) if (check(i)) {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; ++j) {
            if (v[j] % i == 0) {
                dp[0][j] = dp[0][j - 1];
                dp[1][j] = min(dp[0][j - 1], dp[1][j - 1]) + a;
                dp[2][j] = min(dp[1][j - 1], dp[2][j - 1]);
            } else {
                if ((v[j] + 1) % i == 0 || (v[j] - 1) % i == 0) {
                    dp[0][j] = dp[0][j - 1] + b;
                    dp[1][j] = min(dp[1][j - 1], dp[0][j - 1]) + a;
                    dp[2][j] = min(dp[1][j - 1], dp[2][j - 1]) + b;
                } else {
                    dp[0][j] = inf;
                    dp[1][j] = min(dp[1][j - 1], dp[0][j - 1]) + a;
                    dp[2][j] = inf;
                }
            }
        }
        ans = min({ ans, dp[0][n], dp[1][n], dp[2][n] });
    }
    cout << ans << endl;
    return 0;
}