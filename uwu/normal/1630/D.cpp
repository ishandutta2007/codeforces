#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 5;
ll a[MN], dp[MN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        for (int i = 0; i < N; ++i) cin >> a[i];
        int g = 0;
        for (int i = 1; i <= M; ++i){
            int b; cin >> b;
            g = gcd(g, b);
        }
        for (int i = 0; i < g; ++i) dp[i][0] = a[i], dp[i][1] = -a[i];
        for (int i = g; i <= N; ++i){
            dp[i][0] = max(dp[i - g][0] + a[i], dp[i - g][1] - a[i]);
            dp[i][1] = max(dp[i - g][1] + a[i], dp[i - g][0] - a[i]);
        }
        ll ans0 = 0, ans1 = 0;
        for (int i = N - g; i < N; ++i){
            ans0 += dp[i][0];
            ans1 += dp[i][1];
        }
        cout << max(ans0, ans1) << '\n';
    }
}