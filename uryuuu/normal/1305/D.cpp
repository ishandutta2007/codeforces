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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;


int d[1050],vis[1050];
int b[1050];
vector<int>g[1005];

void dfs2(int u,int fa,int root)
{
    int v;
    if(u!=root)
        vis[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        if(v==root)
            continue;
        dfs2(v,u,root);
    }
}

int dfs(int u,int fa,int root)
{
    int v;
    if(u==b[0]||u==b[1])
    {
        if(u!=root)
            return 1;
    }
    int s=0;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        if(v==root)
            continue;
        if(dfs(v,u,root))
        {
            s=1;
            dfs2(v,u,root);
        }
    }
    return s;
}


int main()
{
    sync;
    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        d[u]++;
        d[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt;
    int last=-1;
    while(1)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<=1&&vis[i]==0)
            {
                b[cnt++]=i;
                if(last!=-1&&last==i)
                    swap(b[cnt-1],b[0]);
            }
        }
        last=-1;
        if(cnt==1)
        {
            cout<<"! "<<b[0]<<endl;
            return 0;
        }
        cout<<"? "<<b[0]<<' '<<b[1]<<endl;
        cin>>u;
        d[u]-=2;
        if(b[0]!=u)
            vis[b[0]]=1;
        else
            d[u]++;
        if(b[1]!=u)
            vis[b[1]]=1;
        else
            d[u]++;
        dfs(u,0,u);
        last=u;
    }
    return 0;
}