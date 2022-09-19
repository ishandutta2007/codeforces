#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
vector <int> a[maxn];
bool used[maxn];
int c=(-1);
int sub[maxn];
int n;
int tin[maxn];
int timer=0;
void dfs0(int x)
{
    used[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs0(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
void dfs(int x)
{
    used[x]=true;
    sub[x]=1;
    bool h=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            sub[x]+=sub[v];
            h=(h && (sub[v]<=(n/2)));
        }
    }
    h=(h && (n-sub[x])<=(n/2));
    if(h)
    {
        c=x;
    }
    used[x]=false;
}
int z=1;
map <pair<int,int>,int> u;
bool r;
void dfs1(int x)
{
    //cout<<x<<" x "<<timer<<" timer "<<endl;
    used[x]=true;
    timer+=z;
    tin[x]=timer;
    //cout<<timer<<" timer "<<endl;
    vector <pair<int,int> > h;
    for(auto v:a[x])
    {
        if(!used[v])
        h.push_back({sub[v],v});
    }
    sort(h.begin(),h.end());
    vector <int> z1;
    for(auto v:h) z1.push_back(v.second);
    for(auto v:z1)
    {
        if(!used[v])
        {
            if(x==c && timer>(n/3) && !r)
            {
                z=timer;
                timer=1;
                r=true;
            }
            dfs1(v);
            u[{x,v}]=tin[v]-tin[x];
            u[{v,x}]=tin[v]-tin[x];
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    vector <pair<int,int> > b;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        b.push_back({x,y});
    }
    dfs(0);
    if(c==(-1)) assert(false);
    dfs0(c);
    dfs1(c);
    for(auto h:b)
    {
        cout<<h.first+1<<' '<<h.second+1<<' '<<u[h]<<endl;
    }
    return 0;
}