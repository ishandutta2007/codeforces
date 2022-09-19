#include <bits/stdc++.h>

using namespace std;
int last[5000][5000];
int t[5000][5000];
#define int long long
vector <vector <int> > a;
vector <bool> used;
int c;
void dfs(int x,int pr=(-1))
{
    used[x]=true;
    last[c][x]=pr;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used[a[x][i]])
        {
            dfs(a[x][i],x);
        }
    }
}
vector <int> get(int x,int y)
{
    int h=y;
    vector <int> v;
    while(h!=x)
    {
        v.push_back(t[h][last[x][h]]);
       // cout<<t[h][last[x][h]]<<endl;
        h=last[x][h];
    }
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    a.resize(n);
    int x,y;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y;
        x--;y--;
        t[x][y]=i;
        t[y][x]=i;
        a[x].push_back(y);a[y].push_back(x);
    }
    used.resize(n);
    for(int i=0;i<n;++i)
    {
        c=i;
        for(int j=0;j<n;++j)
        {
            used[j]=false;
        }
        dfs(c);
    }
    cin>>m;
    int w;
    vector <int> ans(n-1);
    for(int i=0;i<(n-1);++i)
    {
        ans[i]=(-1);
    }
    vector <int> v;
    vector <int> d(m);
    vector <pair<int,int> > z(m);
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>w;
        x--;y--;
        v=get(x,y);
        for(int i=0;i<v.size();++i)
        {
            ans[v[i]]=max(ans[v[i]],w);
        }
        d[i]=w;
        z[i]={x,y};
    }
    for(int i=0;i<m;++i)
    {
        v=get(z[i].first,z[i].second);
        int z=1e18;
        for(int i=0;i<v.size();++i)
        {
            z=min(z,ans[v[i]]);
        }
        if(z!=d[i])
        {
            cout<<(-1);
            return 0;
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        cout<<max(ans[i],1LL)<<" ";
    }
    return 0;
}