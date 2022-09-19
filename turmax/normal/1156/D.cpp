#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,int> > a[maxn];
int u0[maxn];
int u1[maxn];
int d0[maxn];
int d1[maxn];
bool used[maxn];
void dfs1(int x)
{
    u0[x]=1;u1[x]=1;
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i].first;
        if(!used[v])
        {
            dfs1(v);
        }
        if(!used[v]){
        if(a[x][i].second==0)
        {
            u0[x]+=u0[v];
        }
        else
        {
            u1[x]+=u1[v];
        }
        }
    }
    used[x]=false;
}
void dfs2(int x)
{
    d0[x]=max(d0[x],u0[x]);d1[x]=max(d1[x],u1[x]);
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i].first;
        if(!used[v]){
        if(a[x][i].second==0)
        {
            d0[v]=d0[x];
        }
        else
        {
            d1[v]=d1[x];
        }
        }
        if(!used[v])
        {
            dfs2(v);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(n-1);++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[x].push_back({y,w});a[y].push_back({x,w});
    }
    dfs1(0);
    d0[0]=u0[0];d1[0]=u1[0];
    dfs2(0);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        //cout<<u0[i]<<' '<<u1[i]<<endl;
        //cout<<d0[i]<<' '<<d1[i]<<endl;
        ans+=(d0[i]*d1[i]-1);
    }
    cout<<ans;
    return 0;
}