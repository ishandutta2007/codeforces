#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <pair<int,int> > u;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    int c[m],d[m];
    for(int i=0;i<m;++i) cin>>c[i]>>d[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            u.push_back({max(0LL,c[j]-a[i]+1),max(0LL,d[j]-b[i]+1)});
        }
    }
    sort(u.begin(),u.end());
    reverse(u.begin(),u.end());
    int currx=u[0].first;
    int curry=0;
    int ans=1e18;
    for(int i=0;i<u.size();++i)
    {
        ans=min(ans,currx+curry);
        if((i+1)<u.size())
        currx=u[i+1].first;
        else
        currx=0;
        curry=max(curry,u[i].second);
        ans=min(ans,currx+curry);
    }
    cout<<ans;
    return 0;
}