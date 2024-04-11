#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e6+5;
int dp[maxn];
int dp1[maxn];
int dp2[maxn];
int pr2[maxn+1];
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
int f1(int n)
{
    int ans=2*dp[n];
    for(int i=1;i<n;++i)
    {
        ans+=(dp2[i]-dp2[i-1])*pr2[n-i];
        ans%=p;
    }
    return ans;
}
int f(int n)
{
    return ((2*dp[n])%p);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[0]=1;
    dp1[0]=1;
    dp2[0]=0;
    int inv6=inv(6);
    int inv2=inv(2);
    for(int i=0;i<maxn;++i)
    {
        dp[i+1]=(((dp1[i]+3)*(dp1[i]+2))%p)*(((dp1[i]+1)*inv6)%p);
        dp[i+1]%=p;
        dp1[i+1]=((dp1[i]+2)%p)*(((dp1[i]+1)*inv2)%p);
        dp1[i+1]%=p;
        dp2[i+1]=((dp1[i]+1)%p)*(((dp1[i])*inv2)%p);
        dp2[i+1]%=p;
    }
    pr2[0]=0;
    for(int i=0;i<maxn;++i)
    {
        int o;
        if(i!=0) o=dp2[i-1];
        else o=0;
        pr2[i+1]=pr2[i]+dp2[i]-o;
        pr2[i+1]%=p;
    }
    int n;
    cin>>n;
    cout<<((((f1(n)-f(n-1))-1)%p)+p)%p;
    return 0;
}