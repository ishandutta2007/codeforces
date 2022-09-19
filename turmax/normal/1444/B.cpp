#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=3e5+5;
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
    int u1=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u1;
        invf[i]=inv(fact[i]);
        u1*=(i+1);
        u1%=p;
    }
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;++i) cin>>a[i];
    sort(a,a+2*n);
    int sum=0;
    for(int i=0;i<n;++i) sum-=a[i];
    for(int i=n;i<(2*n);++i) sum+=a[i];
    sum%=p;
    sum*=c(2*n,n);
    sum%=p;
    cout<<(sum%p+p)%p;
    return 0;
}