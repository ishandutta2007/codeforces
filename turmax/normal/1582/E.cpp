#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
const int sq=505;
int ma[maxn][sq];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=n;i>=0;i--) for(int j=0;j<sq;++j) ma[i][j]=(-1e18);
        ma[n][0]=1e18;
        int a[n];int pr[n];pr[0]=0;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) {pr[i+1]=pr[i]+a[i];}
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=0;j<=min(n-i,sq-1);++j)
            {
                ma[i][j]=ma[i+1][j];if(j==0) continue;
                int val=pr[i+j]-pr[i];
                //cout<<i<<" i "<<j<<" j "<<ma[i+j][j-1]<<" ma "<<endl;
                if(ma[i+j][j-1]>val)
                {
                    ma[i][j]=max(ma[i][j],val);
                }
            }
        }
        int ans=0;
        for(int i=0;i<sq;++i) if(ma[0][i]!=(-1e18)) ans=max(ans,i);
        cout<<ans<<'\n';
    }
    return 0;
}