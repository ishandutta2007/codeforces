#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1e9+7;


vector<int>vv[maxn];
int dis[maxn],disa[maxn],disb[maxn];
int vis[maxn];


void bfs(int st)
{
    mm(dis);
    queue<int>q;
    q.push(st);
    int vis[maxn]={0};
    vis[st]=1;
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        int v;
        q.pop();
        for(int i=0;i<vv[u].size();i++)
        {
            if(vis[vv[u][i]]==0)
            {
                v=vv[u][i];
                vis[v]=1;
                q.push(v);
                dis[v]=dis[u]+1;
            }
        }
        
    }
}


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    bfs(1);
    int a,da=-1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>da)
        {
            a=i;
            da=dis[i];
        }
    }
    bfs(a);
    int b;
    da=-1;
    for(int i=1;i<=n;i++)
    {
        disa[i]=dis[i];
        if(dis[i]>da)
        {
            b=i;
            da=dis[i];
        }
    }
    bfs(b);
    for(int i=1;i<=n;i++)
    {
        disb[i]=dis[i];
    }
    int c=-1;
    for(int i=1;i<=n;i++)
    {
        if(disa[i]+disb[i]+disa[b]>da&&i!=a&&i!=b)
        {
            c=i;
            da=disa[i]+disb[i]+disa[b];
        }
    }
    cout<<da/2<<' '<<endl;
    cout<<a<<' '<<b<<' '<<c<<endl;
    return 0;
}