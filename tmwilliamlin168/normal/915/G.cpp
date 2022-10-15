#include <bits/stdc++.h>
using namespace std;

#define SQ(a) (a)*(a)

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define MAXN 2000000
#define MOD 1000000007

typedef long long ll;

int n, k;
ll dp[MAXN + 1];

ll modPow(ll a, ll p) { return p ? modPow(SQ(a) % MOD, p >> 1) * (p & 1 ? a : 1) % MOD : 1;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    FOR(i, 1, k + 1) dp[i] = modPow(i, n);
    ROF(i, 1, k + 1) {
        dp[i] += MOD - dp[i - 1];
        dp[i] %= MOD;
    }
    ll res = 0, sum = 0;
    FOR(i, 1, k + 1) {
        sum += dp[i];
        sum %= MOD;
        res += i ^ sum;
        res %= MOD;
        int j = 2 * i;
        while(j <= k) {
            dp[j] += MOD - dp[i];
            dp[j] %= MOD;
            j += i;
        }
    }
    cout << res;
}