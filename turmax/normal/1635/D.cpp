#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e5+5;
int dp[maxn];
set <int> o;
bool ok(int x)
{
    if(o.count(x)) return true;
    if(x==0) return false;
    if(x%2==1) return ok(x/2);
    if(x%4==0) return ok(x/4);
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];o.insert(a[i]);}
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        o.erase(a[i]);
        if(!ok(a[i])) v.push_back(a[i]);
        o.insert(a[i]);
    }
    sort(v.begin(),v.end());
    dp[0]=0;
    for(int i=1;i<=x;++i)
    {
        dp[i]=2*dp[i-1];if(i>=3) dp[i]-=dp[i-3];
        if(i<=30)
        {
            dp[i]+=lower_bound(v.begin(),v.end(),(1LL<<i))-lower_bound(v.begin(),v.end(),(1LL<<(i-1)));
        }
        dp[i]%=p;
    }
    cout<<(dp[x]%p+p)%p;
    return 0;
}