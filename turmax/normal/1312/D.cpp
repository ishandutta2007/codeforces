#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
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
int fact[200005];
int c(int n,int k)
{
    return ((fact[n]*inv(fact[n-k]))%p*inv(fact[k]))%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    fact[0]=1;
    for(int i=1;i<200005;++i)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=p;
    }
    int ans=0;
    for(int i=1;i<=(n-1);++i)
    {
        ans+=(c(m,n-1)*(n-2))%p*(c(n-2,i-1));
        ans%=p;
    }
    ans*=inv(2);
    ans+=p;
    ans%=p;
    cout<<ans;
    return 0;
}