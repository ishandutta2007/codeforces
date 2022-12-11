#include <bits/stdc++.h>
using namespace std;
int v[103];
int dp[103][103][103][2];
int main()
{
    ios_base::sync_with_stdio(false);
    long long m,n,w,t,i,j,k=0,pas=1<<15,sc=0,cnt=0,mn=1000000009,nr1=0,nr2=0;
    cin>>n;
    nr2=(n+1)/2;
    nr1=n-nr2;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]==0)
            continue;
        v[i]%=2;
        if(v[i]==0)
            --nr1;
        else
            --nr2;
        ++v[i];
    }
    for(int pz=0;pz<=n;++pz)
    {
        for(int cat1=0;cat1<=n+1;++cat1)
        {
            for(int cat2=0;cat2<=n+1;++cat2)
            {
                dp[pz][cat1][cat2][0]=dp[pz][cat1][cat2][1]=999;
            }
        }
    }
    dp[0][nr1][nr2][0]=dp[0][nr1][nr2][1]=0;
    for(int pz=1;pz<=n;++pz)
    {
        for(int cat1=0;cat1<=n;++cat1)
        {
            for(int cat2=0;cat2<=n;++cat2)
            {
                if(v[pz]==0)
                {
                    dp[pz][cat1][cat2][0]=min(dp[pz][cat1][cat2][0],min(dp[pz-1][cat1+1][cat2][0],dp[pz-1][cat1+1][cat2][1]+1));
                    dp[pz][cat1][cat2][1]=min(dp[pz][cat1][cat2][1],min(dp[pz-1][cat1][cat2+1][0]+1,dp[pz-1][cat1][cat2+1][1]));
                }
                else
                {
                    if(v[pz]==1)
                        dp[pz][cat1][cat2][0]=min(dp[pz][cat1][cat2][0],min(dp[pz-1][cat1][cat2][0],dp[pz-1][cat1][cat2][1]+1));
                    else
                        dp[pz][cat1][cat2][1]=min(dp[pz][cat1][cat2][1],min(dp[pz-1][cat1][cat2][0]+1,dp[pz-1][cat1][cat2][1]));
                }
            }
        }
    }
    cout<<min(dp[n][0][0][0],dp[n][0][0][1]);
    return 0;
}