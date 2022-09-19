#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=205;
int a[maxn][maxn];int f[maxn][maxn];int d[maxn][maxn];int pr[maxn][maxn];int ans[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;for(int i=0;i<n;++i) for(int j=0;j<n;++j) {cin>>a[i][j];assert(a[i][j]>=0);}
    for(int l=n-1;l>=0;--l) {for(int r=l+1;r<=n;++r) {f[l][r]=f[l+1][r];for(int k=l+1;k<r;++k) f[l][r]+=a[l][k];}}
    for(int l=1;l<n;++l) {for(int r=n-1;r>=l;--r) {d[l][r]=d[l][r+1];for(int j=0;j<l;++j) d[l][r]+=a[j][r];}}
    //for(int l=0;l<n;++l) for(int r=l+1;r<=n;++r) {cout<<l<<' '<<r<<' '<<f[l][r]<<" f "<<endl;}
    //for(int l=0;l<n;++l) for(int r=l;r<=n;++r) {cout<<l<<' '<<r<<' '<<d[l][r]<<" d "<<endl;}
    int dp[n+1][n+1];for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) {dp[i][j]=0;}
    //cout<<f[0][n]<<" f "<<endl;
    for(int l=n-1;l>=0;--l) {for(int r=l+1;r<=n;++r)
            {
                if((r-l)==1)
                {
                    dp[l][r]=0;for(int j=0;j<n;++j) dp[l][r]+=a[j][l];
                    //cout<<l<<" l "<<r<<" r "<<dp[l][r]<<" dp "<<endl;
                    continue;
                }
                dp[l][r]=1e18;
                for(int k=l;k<r;++k)
                {
                     int val=dp[l][k]+dp[k+1][r]+f[0][n]-f[l][k]-f[k+1][r]-d[l][r]-f[0][l]-f[r][n];
                     if(dp[l][r]>val) {dp[l][r]=val;pr[l][r]=k;}
                }
                //cout<<l<<" l "<<r<<" r "<<dp[l][r]<<" dp "<<endl;
            }}
    vector<pair<int,pair<int,int> > > cur={{-1,{0,n}}};
    while(!cur.empty())
    {
        pair<int,pair<int,int> > t=cur.back();cur.pop_back();
        pair<int,int> o=t.second;if(o.first>=o.second) continue; if(o.second-o.first==1) {ans[o.first]=t.first+1;continue;}
        int x=pr[o.first][o.second];ans[x]=t.first+1;cur.push_back({x,{o.first,x}});cur.push_back({x,{x+1,o.second}});
    }
    for(int i=0;i<n;++i) cout<<ans[i]<<' ';
    return 0;
}