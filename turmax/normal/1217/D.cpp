#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <bool> used;
vector <int> ts;
int o;
void dfs(int x)
{
    if(used[x])
    {
        return;
    }
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used[a[x][i]])
        {
            dfs(a[x][i]);
        }
    }
    ts[x]=o;
    o--;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    a.resize(n);
    vector <pair<int,int> > b;
    int x,y;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        b.push_back({x,y});
        a[x].push_back(y);
    }
    used.resize(n);
    ts.resize(n);
    o=(n-1);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    for(int i=0;i<n;++i)
    {
        dfs(i);
    }
    int v;
    v=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<a[i].size();++j)
        {
            if(ts[a[i][j]]<ts[i])
            {
                v=1;
            }
        }
    }
    if(v==0)
    {
        cout<<1<<endl;
        for(int i=0;i<m;++i)
        {
            cout<<1<<" ";
        }
        return 0;
    }
    else
    {
        cout<<2<<endl;
        for(int i=0;i<m;++i)
        {
            if(b[i].first>b[i].second)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<2<<" ";
            }
        }
        return 0;
    }
    return 0;
}