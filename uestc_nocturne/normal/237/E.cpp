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
int l;
int mcmf()
{
    int ret=0;
    int flow=0;
    while(spfa())
    {
        int u=ed,mi=oo;
        while(u!=st)
        {
            mi=min(mi,e[pr[u]].c);
            u=e[pr[u]^1].num;
        }
        u=ed;
        flow+=mi;
        ret+=dis[ed]*mi;
        while(u!=st)
        {
            e[pr[u]].c-=mi;
            e[pr[u]^1].c+=mi;
            u=e[pr[u]^1].num;
        }
    }
    if(flow!=l)return -1;
    return ret;
}
char s[120000],t[102000];
int ct[30],tmp[30],Q;
int main()
{
    while(~scanf("%s",s))
    {
        for(int i=0;i<26;i++)ct[i]=0;
        l=strlen(s);
        for(int i=0;i<l;i++)ct[s[i]-'a']++;
        scanf("%d",&Q);
        N=26+Q+2;st=N-2;ed=N-1;
        for(int i=0;i<N;i++)p[i]=-1;K=0;
        for(int i=0;i<Q;i++)
        {
            scanf("%s",t);
            int ll=strlen(t);
            for(int j=0;j<26;j++)
            tmp[j]=0;
            for(int j=0;j<ll;j++)
            tmp[t[j]-'a']++;
            for(int j=0;j<26;j++)
            add(i,Q+j,0,tmp[j]);
            scanf("%d",&ll);
            add(st,i,i+1,ll);
        }
        for(int i=0;i<26;i++)
        add(Q+i,ed,0,ct[i]);
        printf("%d\n",mcmf());
    }
}