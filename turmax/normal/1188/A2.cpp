#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector<int> a[maxn];int deq[maxn];
bool used[maxn];int pr[maxn];int tin[maxn];int tout[maxn];int corn[maxn];int timer=0;
map<pair<int,int>,int> u;int lis[maxn];map<pair<int,int>,int> li;
vector<vector<int> > res;vector<pair<int,int> > ed;
vector<int> h;
void dfs1(int x)
{
    used[x]=true;
    h.push_back(x);
    tin[x]=timer;
    ++timer;
    for(int v:a[x])
    {
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            pr[v]=x;
            dfs1(v);
        }
    }
    ++timer;
    tout[x]=timer;
    used[x]=false;
}
void dfs2(int x)
{
    used[x]=true;
    bool ok=1;
    for(int v:a[x])
    {
        if(!used[v])
        {
            ok=0;
            dfs2(v);
            lis[x]=lis[v];
        }
    }
    if(ok) lis[x]=x;
    used[x]=false;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
void pl(int x,int y,int val)
{
    assert(deq[x]==1 && deq[y]==1);
    if(x==y) return;
    res.push_back({x,y,val});
    while(!pred(x,y))
    {
        u[{x,pr[x]}]+=val;u[{pr[x],x}]+=val;
        x=pr[x];
    }
    while(!pred(y,x))
    {
        u[{y,pr[y]}]+=val;u[{pr[y],y}]+=val;
        y=pr[y];
    }
}
int get(int x,int y)
{
    return u[{x,y}];
}
void go(int x)
{
    vector<pair<int,int> > d;
    for(int v:a[x])
    {
        d.push_back({v,get(x,v)});
    }
    if(d.size()==1)
    {
        int v=d[0].first;
        pl(li[{x,v}],li[{v,x}],-d[0].second);
    }
    else if(d.size()==2)
    {
        int v0=d[0].first;int v1=d[1].first;
        pl(li[{x,v0}],li[{x,v1}],-d[0].second);
    }
    else if(d.size()>=3)
    {
        for(int i=0;i<d.size()-2;++i)
        {
            int v0=d[i].first;int v1=d[i+1].first;int v2=d[i+2].first;
            int u=get(x,v0);int v=get(x,v1);int w=get(x,v2);
            pl(li[{x,v0}],li[{x,v1}],-(u+v-w)/2);
            pl(li[{x,v1}],li[{x,v2}],-(-u+v+w)/2);
            pl(li[{x,v2}],li[{x,v0}],-(u-v+w)/2);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;++i) {int x,y,w;cin>>x>>y>>w;--x;--y;ed.push_back({x,y});ed.push_back({y,x});a[x].push_back(y);a[y].push_back(x);u[{x,y}]=w;u[{y,x}]=w;}
    for(int i=0;i<n;++i) deq[i]=a[i].size();
    dfs1(0);
    for(auto [x,y]:ed)
    {
        dfs2(x);
        li[{x,y}]=lis[y];
    }
    for(int x:h)
    {
        go(x);
    }
    for(auto [key,val]:u)
    {
        if(val!=0) {cout<<"NO";return 0;}
    }
    cout<<"YES"<<'\n';
    cout<<res.size()<<'\n';
    for(auto h:res) {cout<<h[0]+1<<' '<<h[1]+1<<' '<<-h[2]<<'\n';}
    return 0;
}