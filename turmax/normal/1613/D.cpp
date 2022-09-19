#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) {cin>>a[i];a[i]+=2;}
        int dp[n+5][2];for(int i=0;i<=n+4;++i) for(int j=0;j<2;++j) dp[i][j]=0;
        dp[1][0]=1;
        for(int i=0;i<n;++i)
        {
            int x=a[i];
            dp[x][0]=(2*dp[x][0]+dp[x-1][0])%p;
            dp[x-2][1]=(2*dp[x-2][1]+dp[x-2][0])%p;
            dp[x][1]=(2*dp[x][1])%p;
        }
        int ans=0;for(int i=0;i<=n+4;++i) for(int j=0;j<2;++j) {ans+=dp[i][j];ans%=p;}
        cout<<((ans-1)%p+p)%p<<'\n';
    }
    return 0;
}