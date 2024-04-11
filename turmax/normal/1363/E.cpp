#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
int u[maxn];
int c[maxn];
bool used[maxn];
int c1[maxn];
int c2[maxn];
int ans=0;
void dfs1(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            c[v]=min(c[v],c[x]);
            dfs1(v);
        }
    }
    used[x]=false;
}
void dfs2(int x)
{
    used[x]=true;
    int s1=0;int s2=0;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            dfs2(v);
            s1+=c1[v];
            s2+=c2[v];
        }
    }
    if(u[x]==1)
    {
        ++s1;
    }
    else if(u[x]==2)
    {
        ++s2;
    }
    int o=min(s1,s2);
    ans+=2*o*c[x];
    c1[x]=s1-o;
    c2[x]=s2-o;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
        int o1,o2;
        cin>>o1>>o2;
        if(o1==o2)
        {
            u[i]=0;
        }
        if(o1==0 && o2==1)
        {
            u[i]=1;
        }
        if(o1==1 && o2==0)
        {
            u[i]=2;
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs1(0);
    dfs2(0);
    if(c1[0]==0 && c2[0]==0)
    {
        cout<<ans;
    }
    else
    {
        cout<<(-1);
    }
    return 0;
}