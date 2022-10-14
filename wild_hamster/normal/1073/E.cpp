#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
ll a[200500];
ll t[400500];
ll dp[20][2024][2], sum[20][2024][2], p[220];
ll bits(int x) {
    int t = 0;
    while (x) {
        t += x%2;
        x /= 2;
    }
    return t;
}
ll norm(ll &x) {
    x %= MOD;
}
void update(int i, int j, int k, int l, int r, int pw) {

    dp[i+1][j|(1<<k)][l] += dp[i][j][r];
    norm(dp[i+1][j|(1<<k)][l]);
    sum[i+1][j|(1<<k)][l] = (sum[i+1][j|(1<<k)][l] + sum[i][j][r] + dp[i][j][r]*k%MOD*p[pw])%MOD;
}
ll get(ll x, ll K) {
    if (x == 0)
        return 0;
    vector<int> f;
    while (x) {
        f.push_back(x%10);
        x /= 10;
    }
    reverse(f.begin(), f.end());
    int n = f.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 1024; j++)
            for (int k = 0; k < 10; k++)
                dp[i][j][k] = sum[i][j][k] = 0;
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 1024; j++) {
            for (int k = 0; k < f[i]; k++) {
                update(i, j, k, 0, 1, n-i-1);
            }
            update(i, j, f[i], 1, 1, n-i-1);
            for (int k = 0; k < 10; k++) {
                update(i, j, k, 0, 0, n-i-1);
            }
        }
        dp[i+1][0][0] += (dp[i][0][1] + dp[i][0][0])%MOD;
        norm(dp[i+1][0][0]);
        int j = 0;
        for (int k = 1; k < f[i]; k++) {
            update(i, j, k, 0, 1, n-i-1);
        }

        if (f[i] != 0) {

            update(i, j, f[i], 1, 1, n-i-1);
        }
        for (int k = 1; k < 10; k++) {
            update(i, j, k, 0, 0, n-i-1);
        }
    }
    ll ans = 0;
    for (int i = 1; i < 1024; i++) {
        if (bits(i) <= K)
            ans += sum[n][i][0] + sum[n][i][1];
    }
    return ans % MOD;
}
int main() {
    //freopen("input.txt", "r", stdin);
    p[0] = 1;
    for (int i = 1; i <= 20; i++)
        p[i] = p[i-1]*10%MOD;
    ll l, r, k;
    cin >> l >> r >> k;
    //cout << get(r,k) << endl;
    cout << (get(r, k) - get(l-1, k) + MOD)%MOD;
    return 0;
}