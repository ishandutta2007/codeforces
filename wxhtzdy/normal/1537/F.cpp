#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
int a[MAXN],b[MAXN],col[MAXN],par[MAXN];
long long c[MAXN];
vector<int> g[MAXN],ord;
bool vis[MAXN],bip=true;
void dfs(int u,int p)
{
    par[u]=p;
    ord.push_back(u);
    vis[u]=true;
    for(int v:g[u])
    {
        if(!vis[v]) col[v]=col[u]^1,dfs(v,u);
        else bip&=(col[u]!=col[v]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i],g[i].clear(),vis[i]=false;
        for(int i=0;i<n;i++)cin>>b[i];
        long long s=0;
        for(int i=0;i<n;i++) c[i]=a[i]-b[i],s+=c[i];
        for(int i=0;i<m;i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            --t1;--t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }
        bip=true;
        if(s&1){cout<<"NO\n";continue;}
        ord.clear();
        dfs(0,-1);
        if(!bip){cout<<"YES\n";continue;}
        for(int i=n-1;i>0;i--)c[par[ord[i]]]-=c[ord[i]];
        cout<<(c[0]==0?"YES":"NO")<<"\n";
    }
    return 0;
}