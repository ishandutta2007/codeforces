#include<bits/stdc++.h>
using namespace std;

const int N = 5005;

string s;
int n, ans[N], dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.length();
    for (int len = 1; len <= n; len++){
        for (int l = 0; l < n - len + 1; l++){
            int r = l + len;
            if (len == 1){
                dp[l][r] = 1;
                continue;
            }
            if (len == 2){
                dp[l][r] = ((s[l] == s[r - 1]) ? 2 : 0);
                continue;
            }
            if (s[l] != s[r - 1] || !dp[l + 1][r - 1]){
                continue;
            }
            int m = (l + r) / 2;
            dp[l][r] = 1;
            if (len & 1){
                if (dp[l][m] && dp[m + 1][r]){
                    dp[l][r] = dp[l][m] + 1;
                }
            }
            else{
                if (dp[l][m] && dp[m][r]){
                    dp[l][r] = dp[l][m] + 1;
                }
            }
        }
    }
    for (int len = 1; len <= n; len++){
        for (int l = 0; l < n - len + 1; l++){
            ans[dp[l][l + len]]++;
        }
    }
    for (int i = n - 1; i >= 1; i--){
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
}