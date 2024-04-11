/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
const int P=1000000007;
int set[V],nu[V],vis[V];
LL ret;
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y,int va)
{
    int u=find(x);
    int v=find(y);
    if(u==v)return;
    ret+=(LL)nu[u]*nu[v]*va;
    set[u]=v;
    nu[v]+=nu[u];
}
struct Edge{int v,ne;}e[2*V];
int p[V],K;
void add(int u,int v)
{
    e[K].v=v;e[K].ne=p[u];p[u]=K++;
}
struct Node
{
    int id,va;
}q[V];
bool cmp(Node x,Node y)
{
    return x.va>y.va;
}
int n,m,u,v;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i].va);
            q[i].id=i+1;
        }
        memset(p,-1,sizeof(p));K=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        for(int i=1;i<=n;i++)
        vis[i]=0,set[i]=i,nu[i]=1;
        sort(q,q+n,cmp);
        ret=0;
        for(int i=0;i<n;i++)
        {
            u=q[i].id;
            vis[u]=1;
            for(int j=p[u];j!=-1;j=e[j].ne)
            {
                v=e[j].v;
                if(vis[v])
                {
                    U(u,v,q[i].va);
                }
            }
        }
        printf("%.8f\n",ret*2.0/n/(n-1));
    }
}