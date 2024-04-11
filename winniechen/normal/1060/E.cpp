#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 200005
#define ll long long
struct node{int to,next;}e[N<<1];
int n,head[N],cnt,siz[N],num[N];ll ans,f[N],g[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
    siz[x]=1;
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int to1=e[i].to;
        if(to1!=from)
        {
            dfs(to1,x);
            siz[x]+=num[to1],num[x]+=siz[to1];
            f[x]+=g[to1],g[x]+=f[to1]+siz[to1];
        } 
    }
}
void dfs1(int x,int from)
{
    if(from)
        f[x]+=(g[from]-f[x]-siz[x]),g[x]+=(f[from]-g[x])+siz[from]-num[x],
        num[x]=siz[from],siz[x]=num[from];
    ans+=f[x]+g[x];
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int to1=e[i].to;
        if(to1!=from)dfs1(to1,x);
    }
}
int main()
{
    scanf("%d",&n);memset(head,-1,sizeof(head));
    for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,0);dfs1(1,0);printf("%lld\n",ans>>1);
}