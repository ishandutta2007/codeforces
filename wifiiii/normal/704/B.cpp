#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, s, e;
    cin >> n >> s >> e;
    --s, --e;
    vector<int> a(n), b(n), c(n), d(n), x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n; ++i) cin >> c[i];
    for(int i = 0; i < n; ++i) cin >> d[i];
    ll dp[2][n+2][2][2];
    // dp[i][j][k][l]
    // j : the number of components need in-edge and out-edge
    // k : the number of components need in-edge
    // l : the number of components need out-edge
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][0][0][0] = 0;
    for(int i = 0; i < n; ++i) {
        memset(dp[1], 0x3f, sizeof(dp[1]));
        for(int j = 0; j <= n; ++j) {
            for(int k = 0; k < 2; ++k) {
                for(int l = 0; l < 2; ++l) {
                    if(dp[0][j][k][l] >= 1e18) continue;
                    // case 1. add new component (s will add to l, e will add to k)
                    if(i == s) dp[1][j][k][l + 1] = min(dp[1][j][k][l + 1], dp[0][j][k][l] + d[i] - x[i]);
                    else if(i == e) dp[1][j][k + 1][l] = min(dp[1][j][k + 1][l], dp[0][j][k][l] + b[i] - x[i]);
                    else dp[1][j + 1][k][l] = min(dp[1][j + 1][k][l], dp[0][j][k][l] + b[i] + d[i] - 2 * x[i]);
                    // case 2. close one component which need in-edge (e can't do this)
                    if(i != e) {
                        if(i == s) {
                            if(j) dp[1][j - 1][k][l + 1] = min(dp[1][j - 1][k][l + 1], dp[0][j][k][l] + c[i] + x[i]);
                            if(k) dp[1][j][k - 1][l] = min(dp[1][j][k - 1][l], dp[0][j][k][l] + c[i] + x[i]);
                        } else {
                            if(j || k) dp[1][j][k][l] = min(dp[1][j][k][l], dp[0][j][k][l] + c[i] + b[i]);
                        }
                    }
                    // case 3. close one component which need out-edge (s can't do this)
                    if(i != s) {
                        if(i == e) {
                            if(j) dp[1][j - 1][k + 1][l] = min(dp[1][j - 1][k + 1][l], dp[0][j][k][l] + a[i] + x[i]);
                            if(l) dp[1][j][k][l - 1] = min(dp[1][j][k][l - 1], dp[0][j][k][l] + a[i] + x[i]);
                        } else {
                            if(j || l) dp[1][j][k][l] = min(dp[1][j][k][l], dp[0][j][k][l] + a[i] + d[i]);
                        }
                    }
                    // case 4. close two components (s and e can't do this)
                    if(i != s && i != e) {
                        if(k && l) dp[1][j][k - 1][l - 1] = min(dp[1][j][k - 1][l - 1], dp[0][j][k][l] + a[i] + c[i] + 2 * x[i]);
                        if(j && k) dp[1][j - 1][k][l] = min(dp[1][j - 1][k][l], dp[0][j][k][l] + a[i] + c[i] + 2 * x[i]);
                        if(j && l) dp[1][j - 1][k][l] = min(dp[1][j - 1][k][l], dp[0][j][k][l] + a[i] + c[i] + 2 * x[i]);
                        if(j >= 2) dp[1][j - 1][k][l] = min(dp[1][j - 1][k][l], dp[0][j][k][l] + a[i] + c[i] + 2 * x[i]);
                    }
                }
            }
        }
        memcpy(dp[0], dp[1], sizeof(dp[0]));
    }
    cout << dp[0][0][0][0] << '\n';
}