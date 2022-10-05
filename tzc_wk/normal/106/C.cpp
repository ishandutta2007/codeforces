#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,c0,d0,a,b,c,d;
    int dp[10010];
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>c0>>d0;
    for(int i=c0;i<=n;i++)	dp[i]=i/c0*d0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;    
        for(int j=1;j<=a/b;j++)
        	for(int k=n;k>=c;k--)
        		dp[k]=max(dp[k-c]+d,dp[k]);
    }
    cout<<dp[n]<<endl;
    return 0;
}