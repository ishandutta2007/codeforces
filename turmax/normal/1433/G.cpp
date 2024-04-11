#include <bits/stdc++.h>

using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][n];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) {if(i==j) a[i][j]=0;else a[i][j]=1e9;}
    vector <pair<int,int> > v;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[x][y]=w;
        a[y][x]=w;
        v.push_back({x,y});
    }
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<n;++k) a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
    vector <pair<int,int> > z;
    for(int i=0;i<k;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        z.push_back({x,y});
    }
    int ans=1e9;
    for(auto h:v)
    {
        int sum=0;
        for(auto h1:z)
        {
            sum+=min(a[h1.first][h1.second],min(a[h1.first][h.first]+a[h.second][h1.second],a[h1.first][h.second]+a[h.first][h1.second]));
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}