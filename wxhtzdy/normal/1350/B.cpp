#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n+1],dp[n+1];
        for(int i=1;i<=n;i++)scanf("%i",&a[i]),dp[i]=1;
        for(int i=1;i<=n;i++){
            for(int j=i+i;j<=n;j+=i)if(a[i]<a[j]){
                dp[j]=max(dp[j],dp[i]+1);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
        printf("%i\n",ans);
    }
    return 0;
}