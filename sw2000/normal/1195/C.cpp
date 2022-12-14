#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll dp1[maxn],dp2[maxn],dp[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>dp1[i];
    for(int i=1;i<=n;i++)
        cin>>dp2[i];
    dp[1]=max(dp1[1],dp2[1]);

    for(int i=2;i<=n;i++)
    {
        dp1[i]+=max(dp2[i-1],dp[i-2]);
        dp2[i]+=max(dp1[i-1],dp[i-2]);
        dp[i]=max(dp1[i],dp2[i]);
    }

    ll ans=0;
    ans=max(dp[n],dp[n-1]);
    cout<<ans;
}