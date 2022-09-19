#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=400001;
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
    return (u*a)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
int c(int n,int k)
{
    int ans=fact[n];
    ans*=invf[k];
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
    if(k==0)
    {
        cout<<fact[n];
        return 0;
    }
    if(k>=n)
    {
        cout<<0;
        return 0;
    }
    int ans=0;
    int d[n-k+1];
    for(int i=0;i<=(n-k);++i)
    {
        d[i]=c(n,i)*po(i,n);
        d[i]%=p;
        //cout<<i<<" "<<d[i]<<endl;
    }
    int u1=1;
    for(int i=(n-k);i>=0;i--)
    {
        if(i!=(n-k))
        {
            u1*=(n-i);
        }
        u1%=p;
        ans+=(((d[i]*invf[n-k-i])%p*po(-1,n-k-i))%p)*u1;
        ans%=p;
    }
    ans%=p;
    ans*=2;
    ans%=p;
    ans+=p;
    ans%=p;
    cout<<ans;
    return 0;
}