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
const int V=2100;
const int En=500000;
const int oo=2000000000;
struct Edge{int num,ne,len,c;}e[En];
int p[V],K;
void add(int x,int y,int z,int c)
{
//  printf("%d %d %d %d\n",x,y,z,c);
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
                    if(dis[k]>dis[q[(top+1)%V]])
                    {tail=(tail+1)%V;q[tail]=k;}
                    else
                    {q[top]=k;top=(top+V-1)%V;}
                }
            }
        }
    }
    if(dis[ed]==oo)return false;
    return true;
}
void mcmf()
{
    int ret=0;
    int flow=0;
    while(spfa())
    {
        int u=ed;
        int mi=oo;
        while(u!=st)
        {
            mi=min(e[pr[u]].c,mi);
            u=e[pr[u]^1].num;
        }
        u=ed;
        ret+=mi*dis[ed];
        flow+=mi;
        while(u!=st)
        {
            e[pr[u]].c-=mi;
            e[pr[u]^1].c+=mi;
            u=e[pr[u]^1].num;
        }
    }
//  cout<<flow<<" "<<ret<<endl;
}
int a[2100],b[1200],r[2100];
bool cmp(int x,int y)
{return a[x]<a[y];}
int n,tt,M;
void lisan()
{
    sort(r,r+2*n,cmp);
    M=1;int pre=a[r[0]];
    a[r[0]]=1;
    for(int i=1;i<2*n;i++)
    {
        if(a[r[i]]!=pre)
        {pre=a[r[i]];M++;}
        a[r[i]]=M;
    }
}
const int U=1000000000;
int ct[2100],x,i,j,d;
int main()
{
    while(~scanf("%d%d",&n,&tt))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i],&x,&b[i]);
            a[i+n]=a[i]+x;
            r[i]=i;r[i+n]=i+n;
        }
        lisan();
        memset(ct,0,sizeof(ct));
        for(i=0;i<n;i++)
        {
            for(j=a[i];j<a[i+n];j++)
            ct[j]++;
        }
        N=M+2;st=0;ed=M+1;
        memset(p,-1,sizeof(p));K=0;
        for(i=0;i<n;i++)
        {
            add(a[i],a[i+n],b[i],1);
        }
        add(st,1,0,U);
        add(M,ed,0,U);
        for(i=1;i<M;i++)
        {
            if(ct[i]>tt)d=ct[i]-tt;
            else d=0;
            add(i,i+1,0,U-d);
        }
        mcmf();
        for(i=0;i<n;i++)
        {
            if(i)printf(" ");
            if(e[2*i].c==0)printf("0");
            else printf("1");
        }
    }
}