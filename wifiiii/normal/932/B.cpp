#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1000005];
int f(int x)
{
    int x2 = x;
    if(dp[x]!=-1) return dp[x];
    if(x<10) return x;
    int ans=1;
    while(x)
    {
        if(x%10) ans*=x%10;
        x=x/10;
    }
    return dp[x2]=f(ans);
}
int dp2[1000005][11];
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=9;++i) dp[i]=i;
    for(int i=1;i<=1000000;++i) if(dp[i]==-1) f(i);
    for(int i=1;i<=1000000;++i)
    {
        for(int j=1;j<=9;++j)
        {
            if(dp[i] == j) dp2[i][j] = dp2[i-1][j]+1;
            else dp2[i][j] = dp2[i-1][j];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<dp2[r][k] - dp2[l-1][k]<<endl;
    }
}