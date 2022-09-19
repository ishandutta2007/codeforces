#include <bits/stdc++.h>

using namespace std;
#define int long long
int u[200001];
vector <int> parent;
int ans[200001];
int glav(int z)
{
    int x=z;
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return x;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y,w;
    vector <pair<int,pair<int,int> > > c;
    vector <int> a[n];
    map <pair<int,int>,int> b;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y>>w;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
        b[{x,y}]=w;
        c.push_back({w,{x,y}});
    }
    sort(c.begin(),c.end());
    int lp[n];
    parent.resize(n);
    for(int i=0;i<n;++i)
    {
        parent[i]=i;
        lp[i]=1;
    }
    for(int i=0;i<200001;++i)
    {
        u[i]=0;
        ans[i]=0;
    }
    int r1,r2;
    for(int i=0;i<(n-1);++i)
    {
        x=c[i].second.first;
        y=c[i].second.second;
        r1=glav(x);
        r2=glav(y);
        u[c[i].first]+=lp[r1]*lp[r2];
        if(lp[r1]>=lp[r2])
        {
            parent[r2]=r1;
            lp[r1]+=lp[r2];
        }
        else
        {
            parent[r1]=r2;
            lp[r2]+=lp[r1];
        }
    }
    ans[0]=u[0];
    for(int i=0;i<200000;++i)
    {
        ans[i+1]=ans[i]+u[i+1];
    }
    for(int i=0;i<m;++i)
    {
        cin>>x;
        cout<<ans[x]<<" ";
    }
    return 0;
}