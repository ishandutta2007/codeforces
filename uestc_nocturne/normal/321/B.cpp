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
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int V=2100;
const int En=500000;
const int oo=1000000000;
struct Edge{int num,ne,len,c;}e[En];
int p[V],K;
void add(int x,int y,int z,int c)
{
    e[K].num=y;e[K].len=z;e[K].c=c;
    e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].len=-z;e[K].c=0;
    e[K].ne=p[y];p[y]=K++;
}
int N,st,ed,dis[V],q[V],vis[V],pr[V];
bool spfa()
{
    int i,j,k,top,tail;
    for(i=0;i<N;i++){dis[i]=oo;vis[i]=0;}
    top=0;tail=1;q[1]=st;dis[st]=0;vis[st]=1;
    while(top!=tail)
    {
        top=(top+1)%V;
        i=q[top];vis[i]=0;
        for(j=p[i];j!=-1;j=e[j].ne)
        {
            k=e[j].num;
            if(e[j].c&&dis[k]-e[j].len>dis[i])
            {
                dis[k]=e[j].len+dis[i];pr[k]=j;
                if(!vis[k])
                {
                    vis[k]=1;
                    tail=(tail+1)%V;
                    q[tail]=k;
                }
            }
        }
    }
    if(dis[ed]==oo)return false;
    return true;
}
int flow;
int mcmf(bool f)
{
    int ret=0;
    flow=0;
    while(spfa())
    {
        flow++;
        if(f&&dis[ed]>=0)break;
        ret+=dis[ed];
        int u=ed;
        while(u!=st)
        {
            e[pr[u]].c--;
            e[pr[u]^1].c++;
            u=e[pr[u]^1].num;
        }
    }
    return ret;
}
char s[120];
int a[120],b[120],pos[120];
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",s,&a[i]);
            if(s[0]=='A')pos[i]=1;
            else pos[i]=0;
        }
        for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        int ret=0;
        if(n<m)
        {
            N=n+m+3;st=N-2;ed=N-1;
            int ex=N-3;
            for(int i=0;i<N;i++)p[i]=-1;K=0;
            for(int i=0;i<n;i++)
            add(i,ed,0,1);
            for(int i=0;i<m;i++)
            {
                add(st,n+i,0,1);
                add(n+i,ex,-b[i],1);
            }
            add(ex,ed,0,m-n);
            for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            if(pos[j]==1)
            {
                if(b[i]>=a[j])
                add(i+n,j,-b[i]+a[j],1);
            }
            else if(b[i]>a[j])
            {
                add(i+n,j,0,1);
            }
            int tmp=-mcmf(0);
            //printf("%d %d\n",flow,tmp);
            if(flow==m)ret=max(ret,tmp);
        }
        N=n+m+2;st=N-2;ed=N-1;
        for(int i=0;i<N;i++)p[i]=-1;K=0;
        for(int i=0;i<n;i++)
        add(i,ed,0,1);
        for(int i=0;i<m;i++)
        {
            add(st,n+i,0,1);
        }
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(pos[j]==1)
        {
            if(b[i]>=a[j])
            {
                add(i+n,j,-b[i]+a[j],1);
                //printf("%d %d %d\n",i,j,b[i]-a[j]);
            }
        }
        else if(b[i]>a[j])
        {
            add(i+n,j,0,1);
        }
        int tmp=-mcmf(1);
        ret=max(ret,tmp);
        //printf("%d %d\n",flow,tmp);
        printf("%d\n",ret);
    }
}