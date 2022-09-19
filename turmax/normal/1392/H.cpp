#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=4e6+5;
int in[maxn];
int po(int a,int b)
{
    if(b==1) return a;
    if(b & 1)
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
    else
    {
        int u=po(a,b>>1);
        return (u*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
/*int c(int n,int k)
{
    int o=fact[n];
    o*=invf[k];
    o%=p;
    o*=invf[n-k];
    o%=p;
    return o;
}*/
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i)
    {
        if(i%2==0 && i>2)
        {
            in[i]=in[i/2]*in[2];
            in[i]%=p;
            continue;
        }
        if(i%3==0 && i>3)
        {
            in[i]=in[i/3]*in[3];
            in[i]%=p;
            continue;
        }
        in[i]=inv(i);
    }
    /*int u=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(fact[i]);
        u*=(i+1);
        u%=p;
    }*/
    int n,m;
    cin>>n>>m;
    int f[n+1];
    int g[n+1];
    g[1]=1;
    for(int i=2;i<=n;++i)
    {
        g[i]=1+((g[i-1]*(i-1))%p*in[m+i-1])%p;
        g[i]%=p;
    }
    f[0]=1;
    for(int i=1;i<=n;++i)
    {
        int ans=(m+i)*in[i];
        ans%=p;
        ans+=((f[i-1]*(m+i+1))%p)*in[m+i];
        ans%=p;
        ans-=g[i]*in[i+m];
        ans%=p;
        f[i]=ans;
    }
    cout<<(f[n]%p+p)%p;
    return 0;
}