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
const int V=50010;
struct Edge{int num,ne,len;}e[V*2];
int p[V],K,ma[V],id[V],dis[V],vis[V],k,le;
int ans,num,sum[V];
void add(int x,int y,int z)
{
    e[K].num=y;e[K].len=z;
    e[K].ne=p[x];p[x]=K++;
} 
void dfs(int x,int f)
{
    sum[x]=1;ma[x]=0;
    for(int i=p[x];i!=-1;i=e[i].ne)
    {
        int j=e[i].num;
        if(j==f||vis[j])continue;
        dfs(j,x);
        sum[x]+=sum[j];
        ma[x]=max(ma[x],sum[j]);
    }
    id[num++]=x;
}
int find(int x)
{
    num=0;dfs(x,0);
    int Id=-1;
    for(int i=0;i<num;i++)
    {
        ma[id[i]]=max(ma[id[i]],num-sum[id[i]]);
        if(Id==-1||ma[Id]>ma[id[i]])
        Id=id[i];
    }
    return Id;
}
void Dis(int x,int D,int f)
{
    dis[le++]=D;
    for(int i=p[x];i!=-1;i=e[i].ne)
    {
        int j=e[i].num;
        if(j==f||vis[j])continue;
        Dis(j,D+e[i].len,x);
    }
}
void Cal1(int x)
{
    le=0;
    Dis(x,0,0);
//  printf("%d ",le);
    sort(dis,dis+le);
    int l,r;
    l=0;r=le-1;
    while(l<r)
    {
        if(dis[l]+dis[r]<=k)
        {
            ans+=(r-l);
            l++;
        }
        else r--;
    }
//  printf("%d ",ans);
}
void Cal2(int x)
{
    vis[x]=1;
    for(int i=p[x];i!=-1;i=e[i].ne)
    {
        int j=e[i].num;
        if(vis[j])continue;
        le=0;
        Dis(j,e[i].len,x);
        sort(dis,dis+le);
        int l,r;
        l=0;r=le-1;
        while(l<r)
        {
            if(dis[l]+dis[r]<=k)
            {
                ans-=(r-l);
                l++;
            }
            else r--;
        }
    }
//  printf("%d ",ans);
}
void Div(int x)
{
    x=find(x);
//  printf("%d ",x);
    Cal1(x);
    Cal2(x);
//  printf("%d\n",ans);
    for(int i=p[x];i!=-1;i=e[i].ne)
    {
        int j=e[i].num;
        if(vis[j]==0)Div(j);
    }
}
int n,x,y,z,i;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(i=1;i<=n;i++)p[i]=-1;K=0;
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y,1);add(y,x,1);
        }
        for(i=1;i<=n;i++)vis[i]=0;
        ans=0;Div(1);int ret=ans;
        k--;
        for(i=1;i<=n;i++)vis[i]=0;
        ans=0;Div(1);
        printf("%d\n",ret-ans);
    }
}