#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1;
int dp[MN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<ll> a(N + 1), ex(N + 1);
        for (int i = 1; i <= N; ++i) cin >> a[i];
        ll X; cin >> X;
        ms(dp, 0);
        for (int i = 1; i <= N; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if (ex[i - 1] + a[i] - X >= 0){
                if (dp[i - 1][0] == dp[i - 1][1]){
                    dp[i][1] = dp[i - 1][1] + 1;
                    ex[i] = max(min(ex[i - 1] + a[i] - X, a[i] - X), a[i] - X);
                }
                else if (dp[i - 1][0] > dp[i - 1][1]){
                    dp[i][1] = dp[i - 1][0] + 1;
                    ex[i] = a[i] - X;
                }
                else{
                    dp[i][1] = dp[i - 1][1] + 1;
                    ex[i] = min(ex[i - 1] + a[i] - X, a[i] - X);
                }
            }
            else{
                dp[i][1] = dp[i - 1][0] + 1;
                ex[i] = a[i] - X;
            }
            // cout << dp[i][1] << " " << ex[i] << " | ";
        }
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }
}