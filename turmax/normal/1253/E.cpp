#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <pair<int,int> > a(n);
    int x,y;
    int mi=1e18;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        a[i]={x,y};
        mi=min(mi,x-y);
    }
    a.push_back({0,0});
    int ans[m+1];
    ans[0]=0;
    int u;
    for(int i=1;i<=m;++i)
    {
        u=1e18;
        for(int j=0;j<=n;++j)
        {
            x=a[j].first;
            y=a[j].second;
            if(x>=i)
            {
                if((x-y)<=i)
                {
                    u=min(u,ans[i-1]);
                }
            }
            else if((x+y)>=i)
            {
                u=min(u,ans[i-1]);
            }
            else
            {
                u=min(u,ans[max(0LL,2*x-i-1)]+i-x-y);
            }
        }
        ans[i]=u;
    }
    cout<<ans[m];
    return 0;
}