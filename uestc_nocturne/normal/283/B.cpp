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
const int V=400100;
const LL ooo=1000000000;
const LL oo=ooo*ooo;
int nxt[V],vis[V],dg[V],in[V],n;
LL a[V];
void dfs(int x)
{
    vis[x]=1;
    if(nxt[x]!=-1)
    {
        if(vis[nxt[x]]==1)
        {in[x]=1;return;}
        if(vis[nxt[x]]==0)
        dfs(nxt[x]);
    }
    vis[x]=2;
}
LL d[V];
void Cal(int x)
{
    vis[x]=1;
    if(x>n)d[x]=a[x-n];
    else d[x]=a[x];
    if(nxt[x]!=-1)
    {
        if(vis[nxt[x]]==0)
        Cal(nxt[x]);
        d[x]+=d[nxt[x]];
        if(in[nxt[x]])
        in[x]=1;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        a[1]=oo;
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            nxt[i]=i+a[i];
            if(nxt[i]>n)nxt[i]=-1;
            else nxt[i]+=n;
            nxt[i+n]=i-a[i];
            if(nxt[i+n]<=0)nxt[n+i]=-1;
        }
        nxt[n+1]=-1;nxt[1]=-1;
        memset(vis,0,sizeof(vis));
        memset(dg,0,sizeof(dg));
        memset(in,0,sizeof(in));
        for(int i=2;i<=n;i++)
        {
            if(nxt[i]!=-1)
            dg[nxt[i]]++;
        }
        in[1]=1;
        for(int i=2;i<=2*n;i++)
        dfs(i);
        memset(vis,0,sizeof(vis));
        for(int i=2;i<=2*n;i++)
        if(!vis[i])
        Cal(i);
        for(int i=1;i<n;i++)
        {
            LL ret=i;
            int now=1+i;
            if(in[now+n])ret=-1;
            else ret+=d[now+n];
            if(ret>=oo)ret-=oo-i;
            cout<<ret<<endl;
        }
    }
}