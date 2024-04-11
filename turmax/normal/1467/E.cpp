#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
vector <int> a[maxn];
vector <bool> dpd[maxn];
map <int,int> o;
int b[maxn];
int h[maxn];
bool used[maxn];
int tin[maxn];
int tout[maxn];
int timer=0;
bool dpu[maxn];
int pr[maxn];
vector <int> z[4*maxn];
vector <int> merg(vector <int> &v1,vector <int> &v2)
{
    vector <int> v;
    int l=0,r=0;
    while(true)
    {
        if(l==v1.size() && r==v2.size())
        {
            return v;
        }
        if(l==v1.size())
        {
            v.push_back(v2[r]);
            ++r;
            continue;
        }
        if(r==v2.size())
        {
            v.push_back(v1[l]);
            ++l;
            continue;
        }
        if(v1[l]<=v2[r])
        {
            v.push_back(v1[l]);
            ++l;
            continue;
        }
        else
        {
            v.push_back(v2[r]);
            ++r;
            continue;
        }
    }
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        z[node]={h[tl]};
        //cout<<node<<" node "<<z[node][0]<<endl;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    z[node]=merg(z[2*node+1],z[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        return upper_bound(z[node].begin(),z[node].end(),val)-lower_bound(z[node].begin(),z[node].end(),val);
    }
    if(tl>=r || tr<=l)
    {
        return 0;
    }
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r,val)+get(2*node+2,tm,tr,l,r,val);
}
int n;
bool dpd1[maxn];
int getsub(int x,int val)
{
    //cout<<tin[x]<<" tin[x] "<<tout[x]<<" tout[x] "<<endl;
    return get(0,0,n,tin[x],tout[x],val);
}
void dfs(int x)
{
    //cout<<x<<" x1 "<<endl;
    tin[x]=timer;
    h[timer]=b[x];
    ++timer;
    used[x]=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            pr[v]=x;
            dfs(v);
        }
    }
    tout[x]=timer;
    used[x]=false;
}
void dfs1(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            dfs1(v);
            dpd[x][i]=(dpd1[v] && !getsub(v,b[x]));
            dpd1[x]=(dpd1[x] && dpd[x][i]);
        }
    }
    used[x]=false;
}
void dfs2(int x)
{
    //cout<<x<<" x "<<endl;
    used[x]=true;
    dpu[x]=(dpu[x] && (getsub(x,b[x])==o[b[x]]));
    //if(dpu[x]) cout<<x<<" rfed "<<endl;
    /*if(pr[x]==1)
    {
        if(!dpd[1][2]) cout<<" gtfr "<<endl;
    }*/
    /*if(pr[x]!=(-1))
    for(int i=0;i<a[pr[x]].size();++i)
    {
        int v=a[pr[x]][i];
        //if(pr[x]==1) cout<<v<<" v "<<endl;
        //if(!dpd[pr[x]][i] && pr[x]==1) cout<<v<<" vrfed "<<endl;
        if(v!=x && v!=pr[pr[x]])
        {
            dpu[x]=(dpu[x] && dpd[pr[x]][i]);
        }
    }*/
    int sum=0;
    for(int i=0;i<a[x].size();++i)
    {
        if(pr[a[x][i]]==x)
        {
            if(!dpd[x][i]) ++sum;
        }
    }
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            if(sum!=(1-((int) dpd[x][i])) || !dpu[x]) {dpu[v]=false;}
            dfs2(v);
        }
    }
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) {dpu[i]=true;dpd1[i]=true;}
    for(int i=0;i<n;++i) {cin>>b[i];if(o.count(b[i])) o[b[i]]++; else o[b[i]]=1;}
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        dpd[x].push_back(true);dpd[y].push_back(true);
    }
    pr[0]=(-1);
    dfs(0);
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<a[i].size();++j)
            if(a[i][j]==pr[i])
        dpd[i][j]=true;
    }
    build(0,0,n);
    dfs1(0);
    dfs2(0);
    int ans=0;
    //if(!dpd[1][2]) cout<<" gtfr "<<endl;
    //cout<<pr[2]<<endl;
    for(int i=0;i<n;++i)
    {
        bool h=true;
        for(int j=0;j<a[i].size();++j)
        {
            h=(h && (dpd[i][j]));
        }
        if(dpu[i] && h)
        {
            //cout<<(i+1)<<" i+1 "<<endl;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}