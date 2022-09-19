#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <int> timein;
vector <int> timeout;
vector <bool> used;
int timer=0;
vector <int> pr;
void dfs(int x)
{
    ++timer;
    timein[x]=timer;
    used[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            pr[v]=x;
            dfs(v);
        }
    }
    ++timer;
    timeout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    a.resize(n);
    used.resize(n);
    pr.resize(n);
    timein.resize(n);
    timeout.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        pr[i]=(-1);
    }
    int x,y;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    vector <pair<int,int> > u;
    u.push_back({timeout[0],timeout[0]+1});
    for(int i=1;i<n;++i)
    {
        u.push_back({timeout[i],timeout[pr[i]]});
    }
    vector <int> ans(2*n);
    pair<pair<int,int>,pair<int,int> >  z[2*n];
    for(int i=0;i<n;++i)
    {
        z[2*i]=(make_pair(make_pair(u[i].first,0),make_pair(0,2*i)));
        z[2*i+1]=(make_pair(make_pair(u[i].second,1),make_pair(-u[i].first,2*i+1)));
    }
    sort(z,z+2*n);
    for(int i=0;i<2*n;++i)
    {
        ans[z[i].second.second]=i;
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[2*i]+1<<" ";
        cout<<ans[2*i+1]+1<<"\n";
    }
    return 0;
}