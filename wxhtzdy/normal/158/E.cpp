#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int a[N],b[N],dp[N][N];
int main(){
    int n,m;scanf("%i %i",&n,&m);
    if(n==0)return 0*printf("86400");
    for(int i=0;i<n;i++)scanf("%i %i",&a[i],&b[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=min((i>0&&j>0?dp[i-1][j-1]:1000000000),max((i>0?dp[i-1][j]:0),a[i])+b[i]);
            if(j>=i+1)dp[i][j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++)ans=max(ans,a[i+1]-dp[i][m]);
    ans=max(ans,86400-dp[n-1][m]+1);
    printf("%i",ans);
    return 0;
}