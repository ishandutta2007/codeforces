#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int pr[2*n+1];
    pr[0]=0;
    int o=0;
    for(int i=0;i<2*n;++i)
    {
        pr[i+1]=pr[i]+a[o];
        o+=2;
        o%=n;
    }
    int r=(n+1)/2;
    int ans=0;
    for(int i=0;i<=(2*n-r);++i)
    {
        ans=max(ans,pr[i+r]-pr[i]);
    }
    cout<<ans;
    return 0;
}