#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1, inv2 = (mod + 1) >> 1;

ll dp[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; ll K; cin >> N >> M >> K;
        M = N - M;
        for (int i = 1; i <= N; ++i){
            dp[i][0] = (dp[i - 1][0] + K) % mod;
            for (int j = 1; j <= M; ++j){
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) * inv2 % mod;
            }
        }
        cout << dp[N][M] << '\n';
    }  
}