#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e6+5;
int mi[maxn];
int dp[maxn];
vector <int> getv(int x)
{
    vector <int> v;
    if(x==1) return v;
    v=getv(x/mi[x]);v.push_back(mi[x]);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    mi[0]=1;mi[1]=1;
    for(int i=0;i<maxn;++i) mi[i]=1e18;
    for(int i=0;i<maxn;++i) dp[i]=0;
    for(int i=2;i<maxn;++i)
    {
        for(int j=i;j<maxn;j+=i)
        {
            mi[j]=min(mi[j],i);
        }
    }
    int n,p;
    cin>>n>>p;
    dp[0]=0;dp[1]=1;dp[2]=2;
    int sum=1;
    for(int i=1;i<=n;++i)
    {
        if(i>2) dp[i]+=(2*dp[i-1]);
        dp[i]%=p;
        for(int j=(2*i);j<maxn;j+=i)
        {
            if(j==2) continue;
            dp[j]+=dp[i];
            dp[j]-=dp[i-1];
            dp[j]%=p;
        }
    }
    cout<<(dp[n]%p+p)%p;
    return 0;
}