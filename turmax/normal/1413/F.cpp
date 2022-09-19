#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
vector <int> a[maxn];
vector <int> b[maxn];
int corn[maxn];
int corn1[maxn];
bool used[maxn];
int tin[maxn];
int tout[maxn];
int z[maxn];
int timer=0;
int t[4*maxn][2][2];//color,d1 or d2
int is[4*maxn];
void dfs(int x)
{
    used[x]=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            dfs(v);
        }
    }
    used[x]=false;
}
void dfs1(int x)
{
    used[x]=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            corn1[v]=corn1[x]+1;
            dfs1(v);
        }
    }
    used[x]=false;
}
void dfs2(int x)
{
    tin[x]=timer;
    z[timer]=x;
    ++timer;
    used[x]=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs2(v);
        }
    }
    tout[x]=timer;
    used[x]=false;
}
void build(int node,int tl,int tr)// tr=n
{
    if((tr-tl)==1)
    {
        int x=z[tl];
        t[node][0][0]=corn[x];
        t[node][0][1]=corn1[x];
        t[node][1][0]=(-1e18);
        t[node][1][1]=(-1e18);
        is[node]=0;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    is[node]=0;
    t[node][1][0]=(-1e18);
    t[node][1][1]=(-1e18);
    t[node][0][0]=max(t[2*node+1][0][0],t[2*node+2][0][0]);
    t[node][0][1]=max(t[2*node+1][0][1],t[2*node+2][0][1]);
}
vector<vector<int> > merg(vector<vector<int> > u,vector<vector<int> > v)
{
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            u[i][j]=max(u[i][j],v[i][j]);
        }
    }
    return u;
}
void push(int node)
{
    if(is[node])
    {
        is[2*node+1]^=1;
        is[2*node+2]^=1;
        is[node]=0;
        swap(t[2*node+1][0][0],t[2*node+1][1][0]);
        swap(t[2*node+1][0][1],t[2*node+1][1][1]);
        swap(t[2*node+2][0][0],t[2*node+2][1][0]);
        swap(t[2*node+2][0][1],t[2*node+2][1][1]);
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<2;++j)
            {
                t[node][i][j]=max(t[2*node+1][i][j],t[2*node+2][i][j]);
            }
        }
    }
}
void to(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        is[node]^=1;
        swap(t[node][0][0],t[node][1][0]);
        swap(t[node][0][1],t[node][1][1]);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    push(node);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r);to(2*node+2,tm,tr,l,r);
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            t[node][i][j]=max(t[2*node+1][i][j],t[2*node+2][i][j]);
        }
    }
}
vector<vector<int> > get(int node,int tl,int tr,int l,int r)
{
    if(tr<=l || tl>=r)
    {
        return {{(int)-1e18,(int)-1e18},{(int)-1e18,(int)-1e18}};
    }
    if(tl>=l && tr<=r)
    {
        return {{t[node][0][0],t[node][0][1]},{t[node][1][0],t[node][1][1]}};
    }
    push(node);
    int tm=(tl+tr)/2;
    return merg(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > v;
    pair <int,int> u[n-1];
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        int w;
        cin>>w;
        u[i]={x,y};
        if(w==1) v.push_back({x,y});
        b[x].push_back(w);b[y].push_back(w);
        a[x].push_back(y);a[y].push_back(x);
    }
    corn[0]=0;
    dfs(0);
    int d1;
    int ma=(-1);
    for(int i=0;i<n;++i)
    {
        if(corn[i]>=ma)
        {
            ma=corn[i];
            d1=i;
        }
    }
    corn[d1]=0;
    dfs(d1);
    int d2;
    ma=(-1);
    for(int i=0;i<n;++i)
    {
        if(corn[i]>=ma)
        {
            ma=corn[i];
            d2=i;
        }
    }
    corn1[d2]=0;
    dfs1(d2);
    dfs2(d1);
    build(0,0,n);
    int d2c=0;
    for(auto h:v)
    {
        if(corn[h.first]<=corn[h.second])
        {
            swap(h.first,h.second);
        }
        to(0,0,n,tin[h.first],tout[h.first]);
        if(tin[h.first]<=tin[d2] && tout[h.first]>=tout[d2])
        {
            d2c^=1;
        }
    }
    //cout<<d1<<" "<<d2<<" d1d2 "<<endl;
    vector <vector <int> > v1=get(0,0,n,0,n);
    //cout<<max(v1[0][0],v1[d2c][1])<<endl;
    int m;
    cin>>m;
    while(m--)
    {
        int x;
        cin>>x;
        x--;
        pair <int,int> h=u[x];
        if(corn[h.first]<=corn[h.second])
        {
            swap(h.first,h.second);
        }
        to(0,0,n,tin[h.first],tout[h.first]);
        if(tin[h.first]<=tin[d2] && tout[h.first]>=tout[d2])
        {
            d2c^=1;
        }
        vector <vector <int> > v=get(0,0,n,0,n);
        //cout<<t[0][0][0]<<' '<<t[0][0][1]<<' '<<t[0][1][0]<<' '<<t[0][1][1]<<endl;
        cout<<max(v[0][0],v[d2c][1])<<'\n';
    }
    return 0;
}