#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> has(N+2);
        for (int i = 1; i <= N; ++i){
            char c; cin >> c;
            has[i] = c == '1';
        }
        vector<vector<int>> dp(N+2, vector<int>(2));
        vector<int> a(N+1);
        for (int i = 1; i <= N; ++i){
            cin >> a[i];
            if (has[i]){
                dp[i][0] = dp[i-1][0] + a[i-1];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + a[i];
            }
            else{
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            }
        }
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }   
}