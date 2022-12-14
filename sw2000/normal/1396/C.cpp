#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;

ll a,b,c,d,n;
ll ans,dp[N],arr[N];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",arr+i);
    }
    if(n==1)
    {
        cout<<arr[1]*a+c;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ll bb=min(b,arr[i]*a+a);
        dp[i]=dp[i-1]+a*arr[i]+c;
        if(i!=1)
        {
            dp[i]=min(dp[i],dp[i-2]+a*2+bb+min(b,arr[i-1]*a+a)+d*2);
        }
        if(i==n-1)dp[i]=min(dp[i],dp[i-1]+a+bb+d);
        else dp[i]=min(dp[i],dp[i-1]+a+bb+d*2);
    }
    cout<<dp[n]+(n-1)*d;
    return 0;
}