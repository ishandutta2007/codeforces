#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector <int> a(n);vector <int> b(m);vector <int> c(k);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];
    for(int i=0;i<k;++i) cin>>c[i];
    int dp[n+1][m+1][k+1];
    sort(a.begin(),a.end());sort(b.begin(),b.end());sort(c.begin(),c.end());
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            for(int l=0;l<=k;++l)
            {
                if((i+j+l)<=1 || (i*j+j*l+l*i)==0)
                {
                    dp[i][j][l]=0;
                    continue;
                }
                dp[i][j][l]=0;
                if(i!=0) dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
                if(j!=0) dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l]);
                if(l!=0) dp[i][j][l]=max(dp[i][j][l],dp[i][j][l-1]);
                if(i!=0 && j!=0)
                {
                    dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-1][l]+a[i-1]*b[j-1]);
                }
                if(i!=0 && l!=0)
                {
                    dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l-1]+a[i-1]*c[l-1]);
                }
                if(l!=0 && j!=0)
                {
                    dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l-1]+b[j-1]*c[l-1]);
                }
            }
        }
    }
    cout<<dp[n][m][k];
    return 0;
}