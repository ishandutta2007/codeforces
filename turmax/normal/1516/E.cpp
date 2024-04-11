#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=615;
int fact[maxn];
int invf[maxn];
int nf[maxn];
int invnf[maxn];
int invpo[maxn][maxn];
const int p=1e9+7;
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
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<maxn;++i) for(int j=0;j<maxn;++j) invpo[i][j]=inv(po(i,j));
    int u1=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u1;
        invf[i]=inv(fact[i]);
        u1*=(i+1);
        u1%=p;
    }
    u1=1;
    for(int i=0;i<maxn;++i)
    {
        nf[i]=u1;
        invnf[i]=inv(nf[i]);
        u1*=(n-i);
        u1%=p;
    }
    int dp[k+2][2*k+1][k+1];
    for(int i=0;i<=(k+1);++i)
    {
        for(int j=(2*k);j>=0;j--)
        {
            for(int curr=0;curr<=k;++curr)
            {
            if(j>n)
            {
                dp[i][j][curr]=0;
                continue;
            }
            if(i==0 && j==n)
            {
                dp[i][j][curr]=1;
                continue;
            }
            else if(i==0)
            {
                dp[i][j][curr]=0;
                continue;
            }
            if(i==1)
            {
                dp[i][j][curr]=1;
                continue;
            }
            dp[i][j][curr]=0;
            for(int l=0;((i-1)*l)<=curr && j+(i*l)<=n;++l)
            {
                int x=1;
                x=nf[j+(i*l)];
                x*=invnf[j];
                x%=p;
                x*=invf[l];
                x%=p;
                x*=invpo[i][l];
                x%=p;
                dp[i][j][curr]+=(dp[i-1][j+i*l][curr-(i-1)*l]*x);
                dp[i][j][curr]%=p;
            }
            //cout<<i<<' '<<j<<' '<<curr<<' '<<dp[i][j][curr]<<endl;
            }
        }
    }
    int ans0=dp[k+1][0][0];
    int ans1=0;
    for(int i=1;i<=k;++i)
    {
        if(i%2==0) ans0+=(dp[k+1][0][i]-dp[k+1][0][i-1]);
        else ans1+=(dp[k+1][0][i]-dp[k+1][0][i-1]);
        ans0%=p;ans1%=p;
        if(i%2==0) cout<<((ans0%p)+p)%p<<' ';
        else cout<<((ans1%p)+p)%p<<' ';
    }
    return 0;
}