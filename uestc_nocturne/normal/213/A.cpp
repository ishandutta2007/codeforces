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
const int V=210;
const int oo=1000000000;
struct Edge{int num,ne;}e[V*V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int q[3][V],tail[3],dg[V],tg[V],bel[V],n;
int Cal(int x)
{
    int re=n,u=x,ans=0;
    memset(tail,0,sizeof(tail));
    for(int i=0;i<n;i++)
    {
        tg[i]=dg[i];
        if(tg[i]==0)
        q[bel[i]][tail[bel[i]]++]=i;
    }
    while(re)
    {
        for(int i=0;i<tail[u];i++)
        {
            int v=q[u][i];
            re--;ans++;
            for(int j=p[v];j!=-1;j=e[j].ne)
            {
                int k=e[j].num;
                tg[k]--;
            //  printf("D %d %d %d\n",v,k,tg[k]);
                if(tg[k]==0)
                q[bel[k]][tail[bel[k]]++]=k;
            }
        }
    //  printf("%d %d %d\n",u,re,ans);
        tail[u]=0;u++;u%=3;
        if(re==0)break;
        ans++;
    }
    //printf(" X %d %d\n",x,ans);
    return ans;
}
int x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(p,-1,sizeof(p));K=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&bel[i]);
            bel[i]--;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
                scanf("%d",&y);y--;
                add(y,i);dg[i]++;
            }
        }
        int ret=oo;
        for(int i=0;i<3;i++)
        ret=min(ret,Cal(i));
        printf("%d\n",ret);
    }
}