#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,a[N];
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int dp[n][2];
    for(int i=0;i<n;i++){
        if(i==0||abs(a[i]-a[i-1])>=2)dp[i][0]=1,dp[i][1]=1;
        else{
            if(a[i]==a[i-1]){
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
            }else{
                if(a[i]==a[i-1]+1){
                    dp[i][0]=dp[i-1][1]+1;
                    dp[i][1]=1;
                }else{
                    dp[i][1]=dp[i-1][0]+1;
                    dp[i][0]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    printf("%i",ans);
    return 0;
}