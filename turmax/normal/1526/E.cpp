#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=4e5+5;
int fact[maxn];int invf[maxn];
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
        return (u*a)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    if(n<k || k<0) return 0;
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
        invf[i]=inv(u1);
        u1*=(i+1);
        u1%=p;
    }
    int n,k;
    cin>>n>>k;
    int a[n+1];int pos[n];
    for(int i=0;i<n;++i) {cin>>pos[i];a[pos[i]]=i;}
    a[n]=(-1);
    int cnt1=0,cnt2=0;
    for(int i=0;i<(n-1);++i)
    {
        if(a[pos[i]+1]>a[pos[i+1]+1])
        {
            ++cnt1;
        }
        else
        {
            ++cnt2;
        }
    }
    cout<<c(k+cnt2,n);
    return 0;
}