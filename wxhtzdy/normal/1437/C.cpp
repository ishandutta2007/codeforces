#include <bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    scanf("%i",&tt);
    while(tt--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        sort(a,a+n);
        int dp[n][a[n-1]*n+1];
        for(int i=0;i<n;i++)for(int j=0;j<=a[n-1]*n;j++)dp[i][j]=0;
        for(int i=0;i<n;i++){
            int pref[a[n-1]*n+1];
            if(i!=0){
                pref[0]=dp[i-1][0];
                for(int j=1;j<=a[n-1]*n;j++)pref[j]=min(pref[j-1],dp[i-1][j]);
            }
            for(int j=0;j<=i;j++)dp[i][j]=1e9;
            for(int j=i+1;j<=a[n-1]*n;j++){
                if(i==0||j==0)dp[i][j]=abs(a[i]-j);
                else dp[i][j]=abs(a[i]-j)+pref[j-1];
            }
        }
        int ans=dp[n-1][0];
        for(int i=1;i<=a[n-1]*n;i++)ans=min(ans,dp[n-1][i]);
        printf("%i\n",ans);
    }
    return 0;
}