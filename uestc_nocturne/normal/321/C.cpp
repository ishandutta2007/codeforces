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
struct Edge{int num,ne;}e[V*2];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int ret[V];
int s[V];
int nu[V],set[V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    if(find(x)==find(y))return;
    int rt=find(x);set[rt]=y;
}
int vis[V],mx[V],id[V];
void dfs(int u,int fa)
{
    s[u]=1;vis[u]=1;
    mx[u]=0;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa||ret[v]!=-1)continue;
        dfs(v,u);
        mx[u]=max(mx[u],s[v]);
        s[u]+=s[v];
    }
    mx[u]=max(mx[u],nu[find(u)]-s[u]);
}
int n,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(ret,-1,sizeof(ret));
        memset(p,-1,sizeof(p));K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;
            add(x,y);add(y,x);
        }
        for(int lab=0;lab<36;lab++)
        {
            bool dn=true;
            for(int i=0;i<n;i++)
            if(ret[i]==-1)dn=false;
            if(dn)break;
            memset(nu,0,sizeof(nu));
            memset(vis,0,sizeof(vis));
            for(int i=0;i<n;i++)set[i]=i;
            for(int i=0;i<n;i++)
            if(ret[i]==-1)for(int j=p[i];j!=-1;j=e[j].ne)
            {
                int k=e[j].num;
                if(ret[k]==-1)
                {
                    //if(lab==1)printf("U %d %d\n",i,k);
                    U(i,k);
                }
            }
            for(int i=0;i<n;i++)nu[find(i)]++;
            for(int i=0;i<n;i++)
            if(ret[i]==-1&&!vis[i])
            dfs(i,-1);
            memset(id,-1,sizeof(id));
            for(int i=0;i<n;i++)
            if(ret[i]==-1)
            {
                int u=find(i);
                //if(lab==1)printf("%d %d %d\n",u,i,mx[i]);
                if(id[u]==-1||mx[id[u]]>mx[i])
                id[u]=i;
            }
            for(int i=0;i<n;i++)
            if(id[i]!=-1)ret[id[i]]=lab;
        }
        for(int i=0;i<n;i++)printf("%c ",ret[i]+'A');
        puts("");
    }
}