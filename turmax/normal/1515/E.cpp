#include <bits/stdc++.h>

using namespace std;
#define int long long
int p;
const int maxn=1e5+5;
int fact[maxn];
int invf[maxn];
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
int c(int n,int k)
{
    int ans=fact[n];
    ans*=invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
int f(int n,int k)
{
    int ans=0;
    for(int i=0;i<=k;++i)
    {
        int u=po(p-1,i);
        u*=po(k-i,n);
        u%=p;
        u*=c(k,i);
        u%=p;
        ans+=u;
        ans%=p;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cin>>p;
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(fact[i]);
        u*=(i+1);
        u%=p;
    }
    int ans=0;
    for(int k=1;k<=(n+1)/2;++k)
    {
        int u=po(2,n-2*k+1);
        int z=f(n-k+1,k);
        ans+=((u*z)%p);
        ans%=p;
    }
    cout<<(ans%p+p)%p;
    return 0;
}