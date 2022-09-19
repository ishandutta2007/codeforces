#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
const int p=1e9+7;
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
    if(k<0 || k>n) return 0;
    int ans=fact[n];
    ans%=p;
    ans*=invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
int go(int cnt1,int cnt2,int n,int l,int r)
{
    int ans=0;//(1-l,r-n)
    {ans+=c(n,cnt1)*max(0LL,min((1-l),(r-n)));ans%=p;}
    for(int i=min(1-l,r-n)+1;;++i)
    {
        int o1=(i+l-1);int o2=(i-r+n);
        o1=max(o1,0LL);o2=max(o2,0LL);
        if(o1>cnt1 || o2>cnt2) break;
        ans+=c(cnt1-o1+cnt2-o2,cnt2-o2);
        ans%=p;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;fact[0]=1;invf[0]=1;fact[1]=1;invf[1]=1;
    for(int i=1;i<maxn-1;++i) {u*=(i+1);u%=p;fact[i+1]=u;invf[i+1]=inv(fact[i+1]);}
    int t;cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        int ans=0;
        if(n%2==0)
        {
             int cnt1=n/2;int cnt2=n/2;
             ans+=go(cnt1,cnt2,n,l,r);
             ans%=p;
        }
        else
        {
             int cnt1=(n+1)/2;int cnt2=(n-1)/2;
             ans+=go(cnt1,cnt2,n,l,r);
             ans%=p;
             swap(cnt1,cnt2);
             ans+=go(cnt1,cnt2,n,l,r);
             ans%=p;
        }
        cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}