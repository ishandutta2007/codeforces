#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int best[k+1];
    for(int i=0;i<=k;i++) best[i] = 0;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<=k){
            best[x] = max(best[x],y);
        }
    }
    int dp[k+1];
    int p[k+1];
    p[0] = 0;
    for(int i=1;i<=k;i++){
        p[i] = p[i-1]+a[i-1];
    }
    dp[0] = 0;
    for(int i=1;i<=k;i++){
        dp[i] = 1000000000;
        for(int j=1;j<=i;j++){
            int add = p[i]-p[i+best[j]-j];
            dp[i] = min(dp[i],add+dp[i-j]);
        }
        dp[i] = min(dp[i],dp[i-1]+a[i-1]);
    }
    printf("%d",dp[k]);
}