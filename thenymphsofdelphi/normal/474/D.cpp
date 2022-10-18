#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 5;
int dp[N], s[N];

signed main(){
    int t, n;
    cin >> t >> n;
    for (int i = 0; i < n; i++){
        dp[i] = 1;
    }
    dp[n] = 2;
    for (int i = n + 1; i < N; i++){
        dp[i] = (dp[i - 1] + dp[i - n]) % mod;
    }
    for (int i = 1; i <= N; i++){
        s[i] = (s[i - 1] + dp[i]) % mod;
    }
    while (t--){
        int x, y;
        cin >> x >> y;
        int ans = (s[y] - s[x - 1]) % mod;
        if (ans < 0){
            ans += mod;
        }
        cout << ans << endl;
    }
}//