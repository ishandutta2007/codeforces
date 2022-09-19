#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,int> > a[maxn];
vector <pair<int,int> > b[maxn];
int tout[maxn];
bool used[maxn];
int color[maxn];
int g[maxn];
int pot[maxn];
int timer=0;
void dfs(int x)
{
    used[x]=true;
    ++timer;
    for(auto v:a[x])
    {
        if(!used[v.first])
        {
            dfs(v.first);
        }
    }
    ++timer;
    tout[x]=timer;
}
void dfs2(int x,int c)
{
    color[x]=c;
    used[x]=true;
    for(auto v:b[x])
    {
        if(!used[v.first])
        {
            pot[v.first]=pot[x]+v.second;
            dfs2(v.first,c);
        }
        else if(color[v.first]==c)
        {
            g[c]=__gcd(g[c],abs(pot[v.first]-(pot[x]+v.second)));
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[x].push_back({y,w});
        b[y].push_back({x,w});
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i]) dfs(i);
    }
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i) v.push_back({tout[i],i});
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    vector <int> ts;
    for(int i=0;i<n;++i) ts.push_back(v[i].second);
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<n;++i)
    {
        if(!used[ts[i]]) {pot[i]=0;dfs2(ts[i],ts[i]);}
    }
    //for(int i=0;i<n;++i) cout<<color[i]<<' '<<pot[i]<<endl;
    //for(int i=0;i<n;++i) cout<<g[color[i]]<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int v,s,t;
        cin>>v>>s>>t;
        v--;
        int h=g[color[v]];
        int x;
        if(h!=0) x=s%h;else x=s;
        int y=__gcd(t,h);
        //cout<<x<<' '<<y<<" x y "<<endl;
        if(abs(x)%abs(y)==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}