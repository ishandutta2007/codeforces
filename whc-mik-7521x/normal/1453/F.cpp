#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int dp[N][N],n,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)for(int o=1;o<=n;o++)dp[i][o]=1e9;
        for(int i=1;i<=n;i++)dp[1][i]=0;
        for(int i=2;i<=n;i++){
            int ct=0;
            for(int o=i-1;o;o--){
                if(a[o]+o>=i)dp[i][a[o]+o]=min(dp[i][a[o]+o],dp[o][i-1]+ct),ct++;
            }
            for(int o=i;o<=n;o++)dp[i][o]=min(dp[i][o],dp[i][o-1]);
        }
        printf("%d\n",dp[n][n]);
    }
    return 0;
}