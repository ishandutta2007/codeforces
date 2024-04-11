#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 512;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(N, 1e9);
    dp[0] = -1;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < N; ++j) {
            if(x > dp[j]) {
                dp[j ^ x] = min(dp[j ^ x], x);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) if(dp[i] != 1e9) ++ans;
    cout << ans << '\n';
    for(int i = 0; i < N; ++i) if(dp[i] != 1e9) cout << i << " ";
}