#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
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
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int invm[n+1];
    for(int i=1;i<=n;++i)
    {
        invm[i]=inv(i);
    }
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    if(2*a[n-2]>a[n-1]) {cout<<0;return 0;}
    int dp[n];
    int pr[n+1];
    pr[0]=0;
    dp[0]=invm[n];
    pr[1]=dp[0]*invm[n-1];
    for(int i=1;i<n;++i)
    {
        dp[i]=pr[min(i,(int) (lower_bound(a,a+n,a[i]/2+1)-a))];
        dp[i]+=invm[n];
        dp[i]%=p;
        if(i!=(n-1)) pr[i+1]=pr[i]+(dp[i]*invm[n-1-(upper_bound(a,a+n,a[i]/2)-a)]);
        pr[i+1]%=p;
    }
    int ans=dp[n-1];
    for(int i=1;i<=n;++i)
    {
        ans*=i;
        ans%=p;
    }
    cout<<ans;
    return 0;
}