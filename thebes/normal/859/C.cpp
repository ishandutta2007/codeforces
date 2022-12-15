#include <bits/stdc++.h>
using namespace std;

int dp[55][2], N, i, arr[55];

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++) scanf("%d",&arr[i]);
    for(i=N;i>=1;i--){
        dp[i][0] = max(arr[i]+dp[i+1][1],dp[i+1][0]);
        dp[i][1] = min(arr[i]+dp[i+1][1],dp[i+1][0]);
    }
    printf("%d %d\n",dp[1][1],dp[1][0]);
    return 0;
}