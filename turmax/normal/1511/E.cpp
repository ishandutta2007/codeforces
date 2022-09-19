#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=3e5+5;
int dp[maxn];
int res;
int go(string s)
{
    int curr=0;
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='o') ++curr;
        else
        {
            ans+=dp[curr];
            ans%=p;
            curr=0;
        }
    }
    ans+=dp[curr];
    ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[0]=0;dp[1]=0;
    for(int i=2;i<maxn;++i)
    {
        dp[i]=(2*dp[i-1]+2*dp[i-2]+1)*((3*p+1)/4);
        dp[i]%=p;
    }
    res=0;
    int n,m;
    cin>>n>>m;
    string a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int o=1;
    for(int i=0;i<n;++i)
    {
        res+=go(a[i]);
        res%=p;
    }
    for(int i=0;i<m;++i)
    {
        string h;
        for(int j=0;j<n;++j)
        {
            if(a[j][i]=='o')
            {
                o*=2;
                o%=p;
            }
            h+=a[j][i];
        }
        res+=go(h);
        res%=p;
    }
    res%=p;res+=p;res%=p;
    cout<<(res*o)%p;
    return 0;
}