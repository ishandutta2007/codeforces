#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=5e3+5;
int sum[maxn];
int dp[maxn][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) {dp[0][i]=1;sum[i]=0;}
    for(int cyc=0;cyc<k;++cyc)
    {
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            dp[cyc+1][i]=dp[cyc][i+1];
        }
        else if(i==(n-1))
        {
            dp[cyc+1][i]=dp[cyc][i-1];
        }
        else
        {
            dp[cyc+1][i]=dp[cyc][i-1]+dp[cyc][i+1];
        }
    }
    for(int i=0;i<n;++i) {dp[cyc+1][i]%=p;}
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            sum[i]+=dp[j][i]*dp[k-j][i];
            sum[i]%=p;
        }
    }
    //for(int i=0;i<n;++i) cout<<sum[i]<<' ';
    //cout<<endl;
    int ans=0;
    for(int i=0;i<n;++i) {ans+=(sum[i]*a[i])%p;ans%=p;}
    while(q--)
    {
        int pos,x;
        cin>>pos>>x;
        pos--;
        ans-=(a[pos]*sum[pos])%p;
        a[pos]=x;
        ans+=(a[pos]*sum[pos])%p;
        ans%=p;ans+=p;ans%=p;
        cout<<ans<<'\n';
    }
    return 0;
}