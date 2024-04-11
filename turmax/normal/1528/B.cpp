#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e6+5;
int cnt[maxn];
int dp[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) for(int j=i;j<maxn;j+=i) cnt[j]++;
    int sum=0;
    for(int i=1;i<maxn;++i)
    {
        dp[i]=(sum+cnt[i]);
        dp[i]%=p;
        sum+=dp[i];
        sum%=p;
    }
    int n;
    cin>>n;
    cout<<(dp[n]%p+p)%p;
    return 0;
}