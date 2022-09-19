#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;const int maxn=3e6+5;
int n;
int fact[maxn];int invf[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b & 1)
    {
        int u=po(a,b-1);
        return (u*a)%p;
    }
    else
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    if(k<0 || k>n) return 0;
    int ans=fact[n];ans*=invf[n-k];ans%=p;ans*=invf[k];ans%=p;
    return ans;
}
int f(int x)
{
    int ans=0;
    for(int i=0;i<=n;++i) {ans+=c(3*i,x);ans%=p;}
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u1=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u1;
        u1*=(i+1);
        u1%=p;
    }
    invf[maxn-1]=inv(fact[maxn-1]);
    for(int i=(maxn-2);i>=0;i--)
    {
        invf[i]=(invf[i+1]*(i+1));
        invf[i]%=p;
    }
    int q;
    cin>>n>>q;
    int ans[3*n+1];
    ans[0]=n+1;
    ans[1]=f(1);
    int inv3=inv(3);
    for(int i=2;i<=3*n;++i)
    {
        ans[i]=c(3*n+3,i+1)-3*ans[i-1]-ans[i-2];
        ans[i]%=p;ans[i]*=inv3;ans[i]%=p;
    }
    while(q--)
    {
        int x;
        cin>>x;
        cout<<(ans[x]%p+p)%p<<'\n';
    }
    return 0;
}