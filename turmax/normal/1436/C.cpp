#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e5+5;
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
    int n,x,pos;
    cin>>n>>x>>pos;
    int l=0;int r=n;
    int cnt1=0,cnt2=0;
    while(l<r)
    {
        int m=(l+r)/2;
        if(m<=pos)
        {
            if(m!=pos)
            {
                ++cnt1;
            }
            l=(m+1);
        }
        else
        {
            ++cnt2;
            r=m;
        }
    }
    if(cnt2>(n-x) || cnt1>=x)
    {
        cout<<0;
        return 0;
    }
    cout<<(c(n-1-cnt1-cnt2,x-1-cnt1)*((fact[x-1]*fact[n-x])%p))%p;
    return 0;
}