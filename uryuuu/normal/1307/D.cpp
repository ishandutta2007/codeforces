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
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;

int n,m,k;
int a[maxn],b[maxn];
int vis[maxn];
vector<int>g[maxn];
int deep1[maxn],deepn[maxn];

void bfs1()
{
    deep1[1]=1;
    queue<int>q;
    q.push(1);
    int u,v;
    while(!q.empty())
    {
        u=q.front();
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(deep1[v])
                continue;
            deep1[v]=deep1[u]+1;
            q.push(v);
        }
        q.pop();
    }
}


void bfsn()
{
    
    deepn[n]=1;
    queue<int>q;
    q.push(n);
    int u,v;
    while(!q.empty())
    {
        u=q.front();
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(deepn[v])
                continue;
            deepn[v]=deepn[u]+1;
            q.push(v);
        }
        q.pop();
    }
}


int main()
{
    sync;
    cin>>n>>m>>k;
    int x;
    for(int i=0;i<k;i++)
    {
        cin>>x;
        a[i]=x;
//        b[i]=x;
    }
    int u,v;
    int flag=0;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs1();
    bfsn();
    vector<pii>V;
    for(int i=0;i<k;i++)
    {
        V.push_back(pii(deep1[a[i]]-deepn[a[i]],a[i]));
    }
    sort(V.begin(),V.end());
    int zd=0;
    for(int i=1;i<=n;i++)
    {
        deep1[i]--;
        deepn[i]--;
    }
    int tmp=0;
    for(int i=0;i<V.size();i++)
    {
        if(i!=0)
        {
            zd=max(zd,tmp+deepn[V[i].second]+1);
        }
        tmp=max(deep1[V[i].second],tmp);
    }
    cout<<min(zd,deep1[n])<<endl;
    return 0;
}