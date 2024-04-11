#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector <int> pr[m];
    for(int i=0;i<m;++i)
    {
        pr[i].push_back(0);
    }
    int t;
    for(int i=0;i<n;++i)
    {
        t=(i%m);
        pr[t].push_back(pr[t][pr[t].size()-1]+a[i]);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=pr[(i%m)][(i-(i%m))/m+1];
        cout<<ans<<" ";
    }
    return 0;
}