#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, mod;
    cin >> n >> mod;
    vector<int> dp(n + 1), sdp(n + 2);
    dp[n] = sdp[n] = 1;
    for(int i = n - 1; i >= 1; --i) {
        dp[i] = sdp[i + 1];
        for(int j = 2; ; ++j) {
            int l = j * i, r = min(n + 1, (i + 1) * j);
            if(l > n + 1) break;
            dp[i] = (dp[i] + sdp[l] - sdp[r]) % mod;
            if(dp[i] < 0) dp[i] += mod;
        }
        sdp[i] = (sdp[i+1] + dp[i]) % mod;
    }
    cout << dp[1] << endl;
}