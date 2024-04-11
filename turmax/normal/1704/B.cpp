#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<int,int> in(pair<int,int> a,pair<int,int> b)
{
    return {max(a.first,b.first),min(a.second,b.second)};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,x;cin>>n>>x;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        pair<int,int> cur={-1e18,1e18};int ans=0;for(int i=0;i<n;++i) {pair<int,int> h={a[i]-x,a[i]+x};pair<int,int> cur1=in(cur,h);if(cur1.first>cur1.second) {++ans;cur=h;} else {cur=cur1;}}
        cout<<ans<<'\n';
    }
    return 0;
}