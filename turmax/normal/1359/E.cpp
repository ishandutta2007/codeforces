#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=5e5+5;
int fact[maxn];
int invf[maxn];
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
int c(int n,int k)
{
    if(k>=(n+1))
    {
        return 0;
    }
    int ans=fact[n]*invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(fact[i]);
        u*=(i+1);
        u%=p;
    }
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int x=(n/i)-1;
        ans+=c(x,k-1);
        ans%=p;
    }
    cout<<ans;
    return 0;
}