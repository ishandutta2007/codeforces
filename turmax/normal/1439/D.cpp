#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=505;
int p;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int fact[maxn];
int invf[maxn];
int c3[maxn][maxn];
int c(int n,int k)
{
    return c3[n][k];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>p;
    int u1=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u1;
        u1*=(i+1);
        u1%=p;
    }
    for(int i=0;i<maxn;++i)
    {
        for(int j=0;j<maxn;++j)
        {
            if(j==0) c3[i][j]=1;
            else if(i==0) c3[i][j]=0;
            else if(i>j) c3[i][j]=c3[i-1][j-1]+c3[i-1][j];
            else if(i==j) c3[i][j]=1;
            c3[i][j]%=p;
        }
    }
    int dp1[n+1];
    dp1[0]=1;
    int dp2[n+1];
    dp2[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp1[i]=0;
        dp2[i]=0;
        for(int j=0;j<i;++j)
        {
            dp1[i]+=(((((dp1[j]*dp1[i-1-j])%p)*(i+1))%p)%p)*c(i-1,j);
            dp2[i]+=((((((dp1[j]*dp2[i-j-1])%p)*(i+1)+((dp2[j]*dp1[i-j-1])%p)*(i+1)+((dp1[j]*dp1[i-1-j])%p)*((((i-1-j)*(i-j)+j*(j+1))/2)%p))%p)%p)%p)*c(i-1,j);
            dp2[i]%=p;
            dp1[i]%=p;
            //cout<<dp1[i]<<" "<<dp2[i]<<endl;
        }
    }
    //cout<<dp2[2]<<endl;
    int dp3[n+1][n+1];
    int dp4[n+1][n+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            dp3[i][j]=0;
            dp4[i][j]=0;
        }
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            for(int k=0;k<=j;++k)
            {
                 if(k!=j)
                 dp3[i][j]+=((dp3[i-k-1][j-k]*dp1[k])%p)*c(j,k);
                 else
                 dp3[i][j]+=dp1[k];
                 dp3[i][j]%=p;
                 if(k!=j)
                 dp4[i][j]+=((dp4[i-k-1][j-k]*dp1[k]+dp2[k]*dp3[i-k-1][j-k])%p)*c(j,k);
                 else
                 dp4[i][j]+=dp2[k];
                 dp4[i][j]%=p;
            }
        }
    }
    cout<<dp4[n][m];
    return 0;
}