#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200000;
vector <int> a[maxn];
bool used[maxn];
int corn[maxn];
int sb[maxn];
int color[maxn];
int pr[maxn];
int res[maxn];
void dfs(int x)
{
    int v;
    used[x]=true;
    sb[x]=color[x];
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            pr[v]=x;
            corn[v]=corn[x]+1;
            dfs(v);
            if(sb[v]>=0)
            {
                sb[x]+=sb[v];
            }
        }
    }
}
void go(int x)
{
    int ans=sb[x];
    if(x==0)
    {
        res[x]=ans;
        return;
    }
    else
    {
        if(ans>=0)
        {
            res[x]=max(sb[x],res[pr[x]]);
            return;
        }
        else
        {
            res[x]=max(sb[x],res[pr[x]]-1);
            return;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    corn[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>color[i];
        if(color[i]==1)
        {
            color[i]=1;
        }
        else
        {
            color[i]=(-1);
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    vector <pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        v.push_back({corn[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        go(v[i].second);
    }
    for(int i=0;i<n;++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}