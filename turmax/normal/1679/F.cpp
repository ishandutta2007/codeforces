#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int p=998244353;
const int maxn=5e4+5;
bool ok[10][10];
int msk[10];
int dp[maxn][1<<10];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<10;++i) {for(int j=0;j<10;++j) ok[i][j]=true; msk[i]=1023;}
    int n;cin>>n;
    int m;cin>>m;for(int i=0;i<m;++i) {int x,y;cin>>x>>y;ok[x][y]=false;ok[y][x]=false;msk[x]-=(1<<y);msk[y]-=(1<<x);}
    dp[0][(1<<10)-1]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(1<<10);++j)
        {
            for(int k=0;k<10;++k)
            {
                if(!(j & (1<<k))) continue;
                int msk1=j;
                for(int l=0;l<k;++l) {if(!ok[k][l]) msk1 &= (1023-(1<<l));}
                msk1|=msk[k];
                dp[i+1][msk1]+=dp[i][j];if(dp[i+1][msk1]>=p) dp[i+1][msk1]-=p;
            }
        }
    }
    int ans=0;for(int mask=0;mask<(1<<10);++mask) {ans+=dp[n][mask];if(ans>=p) ans-=p;}
    cout<<ans;
    return 0;
}