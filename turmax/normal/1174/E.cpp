#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
const int maxn=1000001;
bool used[maxn];
vector <int> v[maxn];
int fact[maxn];
int invf[maxn];
int sz[maxn];
int dp[maxn];
int inv1[maxn];
int n;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
int go(int x)
{
    return (n/x);
}
int c(int n,int k)
{
    return ((fact[n]*invf[k])%p*invf[n-k])%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;
    used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            v[i].push_back(i);
            for(int j=2;(i*j)<maxn;++j)
            {
                if(!used[i*j])
                {
                    used[i*j]=true;
                }
                int x=(i*j);
                v[i*j].push_back(i);
                while(x%i==0)
                {
                    sz[i*j]++;
                    x/=i;
                }
            }
        }
    }
    for(int i=1;i<maxn;++i)
    {
        inv1[i]=inv(i);
    }
    int u=1;
    int invu=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=invu;
        u*=(i+1);
        invu*=inv1[i+1];
        invu%=p;
        u%=p;
    }
    cin>>n;
    dp[0]=0;
    dp[1]=1;
    int ma=0;
    for(int i=2;i<=n;++i)
    {
        ma=max(ma,sz[i]);
        int ans=0;
        for(int j=0;j<v[i].size();++j)
        {
            int u=v[i][j];
            u=(i/u);
            int z=go(u)-go(i);
            int r=n-go(u);
            int m=((c(z+r,r)*z)%p*inv1[z+r])%p;
            m*=fact[z];
            m%=p;
            ans+=(m*dp[u]);
            ans%=p;
        }
        dp[i]=ans;
    }
    int sum=0;
    for(int i=2;i<=n;++i)
    {
        if(ma==sz[i])
        {
            sum+=dp[i];
            sum%=p;
        }
    }
    cout<<sum;
    return 0;
}