#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
int n;
int sz;
int sz2;
vector <int> a[maxn];
set <pair<int,int> > o;
bool used[maxn];
int sub[maxn];
bool isc[maxn];
bool can[maxn];
void dfs(int x)
{
    used[x]=true;
    isc[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            sub[x]+=sub[v];
            if(sub[v]>(n/2))
            {
                isc[x]=false;
            }
        }
    }
    if((n-sub[x])>(n/2))
    {
        isc[x]=false;
    }
    used[x]=false;
}
void dfs1(int x)
{
    used[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v] && !o.count({x,v}))
        {
            dfs(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
void dfs3(int x)
{
    //cout<<x<<" x "<<endl;
    used[x]=true;
    bool h=can[x];
    if(!h)
    can[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v] && !o.count({v,x}))
        {
            //cout<<x<<" x "<<v<<" v "<<endl;
            dfs3(v);
            sub[x]+=sub[v];
            if(sub[v]>(n/2))
            {
                if(!h)
                can[x]=false;
            }
        }
    }
    //cout<<sub[x]<<" sub[x] "<<endl;
    if((sz-sub[x])>(n/2))
    {
        if(!h)
        can[x]=false;
    }
    //if(can[x]) cout<<x<<" rfde "<<endl;
    used[x]=false;
}
void check(pair <int,int> u)
{
    o.clear();
    o.insert(u);o.insert({u.second,u.first});
    dfs1(u.first);sz=sub[u.first];dfs1(u.second);if(sub[u.second]<=(n/2)) dfs3(u.first);
    dfs1(u.second);sz=sub[u.second];dfs1(u.first);if(sub[u.first]<=(n/2)) dfs3(u.second);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    check({0,0});
    dfs(0);
    int c=0;
    for(int i=0;i<n;++i)
    {
        if(isc[i])
        {
            c=i;
            break;
        }
    }
    //cout<<c<<" c "<<endl;
    dfs1(c);
    vector <pair<int,int> > h;
    for(auto v:a[c])
    {
        h.push_back({-sub[v],v});
    }
    sort(h.begin(),h.end());
    //cout<<h[0].second<<' '<<h[1].second<<endl;
    check({c,h[0].second});
    if(h.size()>=2)
    {
        check({c,h[1].second});
    }
    for(int i=0;i<n;++i)
    {
        if(can[i]) cout<<1<<' ';
        else cout<<0<<' ';
    }
    return 0;
}