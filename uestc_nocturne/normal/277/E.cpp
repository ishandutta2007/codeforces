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
const int V=900;
const int En=500*500;
const double oo=1e9;
struct Edge{int num,ne,c;double len;}e[En];
int p[V],K;
void add(int x,int y,double z,int c)
{
    e[K].num=y;e[K].len=z;e[K].c=c;
    e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].len=-z;e[K].c=0;
    e[K].ne=p[y];p[y]=K++;
}
int N,st,ed,q[V],vis[V],pr[V];
double dis[V];
bool spfa()
{
    int i,j,k,top,tail;
    for(i=0;i<N;i++){dis[i]=oo;vis[i]=0;}
    top=0;tail=1;q[1]=st;dis[st]=0.0;vis[st]=1;
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
    if(dis[ed]+10>=oo)return false;
    return true;
}
int n;
double mcmf()
{
    double ret=0.0;
    int flow=0;
    while(spfa())
    {
        flow++;
        ret+=dis[ed];
        int u=ed;
        while(u!=st)
        {
            e[pr[u]].c--;
            e[pr[u]^1].c++;
            u=e[pr[u]^1].num;
        }
    }
    if(flow!=n-1)return -1.0;
    return ret;
}
int x[V],y[V];
int sqr(int x){return x*x;}
double Dis(int i,int j)
{
    return sqrt(1.0*sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
        N=2*n+2;st=N-2;ed=N-1;
        for(int i=0;i<N;i++)p[i]=-1;K=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(y[i]>y[j])add(i,j+n,Dis(i,j),1);
        for(int i=0;i<n;i++)add(st,i,0,2);
        for(int i=0;i<n;i++)add(i+n,ed,0,1);
        double ret=mcmf();
        if(ret<-0.5)puts("-1");
        else printf("%.10f\n",ret);
    }
}