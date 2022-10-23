#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int a[n];for(int i=0;i<n;++i) cin>>a[i];
    vector<pair<int,int> > v;for(int i=0;i<n;++i) v.push_back({a[i]+a[(i+1)%n],i});
    sort(v.begin(),v.end());int ans[n];for(int i=0;i<n;++i) ans[v[i].second]=i;
    for(int i=0;i<n;++i) cout<<ans[i]<<' ';
    return 0;
}