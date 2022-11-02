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
const int oo=2000000000;
struct Edge{int num,ne,len;}e[2*V];
int p[V],K;
void add(int x,int y,int z)
{
    e[K].num=y;e[K].len=z;
    e[K].ne=p[x];p[x]=K++;
}
int n,m;
int d[V],st[V],ct[V],t[V],nxt[V];
int find(int id,int tt)
{
    int lo=-1,up=ct[id],mid;
    while(lo+1<up)
    {
        mid=(lo+up)/2;
        if(t[st[id]+mid]<=tt)lo=mid;
        else up=mid;
    }
    if(lo==-1)return tt;
    return max(tt,nxt[st[id]+lo]);
}
int q[V],vis[V];
int spfa()
{
    int i,j,k,top,tail;
    for(i=0;i<n;i++)
    {
        vis[i]=0;
        d[i]=oo;
    }
    vis[0]=1;d[0]=0;
    tail=1;top=0;q[1]=0;
    while(top!=tail)
    {
        top=(top+1)%V;
        i=q[top];vis[i]=0;
        for(int j=p[i];j!=-1;j=e[j].ne)
        {
            k=e[j].num;int te=find(i,d[i])+e[j].len;
            if(d[k]>te)
            {
                d[k]=te;
                if(!vis[k])
                {
                    vis[k]=1;
                    tail=(tail+1)%V;
                    q[tail]=k;
                }
            }
        }
    }
    if(d[n-1]>=oo)return -1;
    return d[n-1];
}
int x,y,z;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)p[i]=-1;K=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;y--;add(x,y,z);add(y,x,z);
        }
        int now=0;
        for(int i=0;i<n;i++)
        {
            st[i]=now;
            scanf("%d",&ct[i]);
            for(int j=0;j<ct[i];j++)
            scanf("%d",&t[j+st[i]]);
            now+=ct[i];
            nxt[now-1]=t[now-1]+1;
            for(int j=now-2;j>=now-ct[i];j--)
            if(t[j]+1==t[j+1])nxt[j]=nxt[j+1];
            else nxt[j]=t[j]+1;
        }
        printf("%d\n",spfa());
    }
}