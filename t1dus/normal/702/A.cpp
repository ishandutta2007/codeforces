#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (!i) dp[i] = 1;
        else{
            if (a[i] > a[i-1]){
                dp[i] = 1+dp[i-1];
            }
            else{
                dp[i] = 1;
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
}