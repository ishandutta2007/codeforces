#include <bits/stdc++.h>

using namespace std;
const int p=998244353;
const int inv2=(p+1)/2;
const int maxn=2e5+5;
const int sq=640;
int dp[maxn];int dp2[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    for(int j=sq-1;j>=0;--j)
        {
            for(int i=0;i<=n;++i) {dp2[i]=dp[i];}
    for(int i=0;i<=n;++i)
    {
            if(i==0) {dp[i]=1;continue;}
            int o=k+j;
            if(o<=i) {dp[i]=dp[i-o]+dp2[i-o];if(dp[i]>=p) dp[i]-=p;}
    }
            }
    for(int i=1;i<=n;++i)
    {
        cout<<(dp[i]*1LL*inv2)%p<<' ';
    }
    return 0;
}