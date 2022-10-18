#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=2e5+100;

vector<int> g[N];
pair<int,int> down[N];
int ans,a,b,c;

pair<int,int> add(pair<int,int> p)
{
    return {p.first+1,p.second};
}

pair<int,int> dfs_down(int v,int p)
{
    vector<pair<int,int>> res;
    for(int to:g[v])
        if(to!=p)
            res.push_back(dfs_down(to,v));
    sort(res.begin(),res.end(),greater<>());
    if(res.size()>=3)
    {
        int val=res[0].first+res[1].first+res[2].first,
            x=res[0].second,
            y=res[1].second,
            z=res[2].second;
        if(val>ans)
            ans=val,a=x,b=y,c=z;
    }
    if(res.empty())
        return down[v]={1,v};
    else
        return down[v]=add(res[0]);
}

void dfs_up(int v,int p,pair<int,int> up)
{
    vector<pair<int,int>> res;
    for(int to:g[v])
        if(to!=p)
            res.push_back(down[to]);
    sort(res.begin(),res.end(),greater<>());
    if(res.size()>=2)
    {
        int val=res[0].first+res[1].first+up.first,
            x=res[0].second,
            y=res[1].second,
            z=up.second;
        if(val>ans)
            ans=val,a=x,b=y,c=z;
    }
    res.push_back({-1e9,0});
    for(int to:g[v])
        if(to!=p)
            dfs_up(to,v,add(max(up,res[down[to]==res[0]])));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> leaves;
    vector<int> nonleaves;
    for(int i=1;i<=n;i++)
        if(g[i].size()==1)
            leaves.push_back(i);
        else
            nonleaves.push_back(i);
    if(leaves.size()==2)
        cout<<n-1<<"\n"<<leaves[0]<<" "<<leaves[1]<<" "<<nonleaves[0],
        exit(0);
    int root=nonleaves[0];
    dfs_down(root,0);
    dfs_up(root,0,{-1e9,0});
    cout<<ans<<"\n"<<a<<" "<<b<<" "<<c;
}