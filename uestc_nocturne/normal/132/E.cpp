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
const int oo=1000000000;
const int U=100000;
const int V=1200;
const int En=2100000;
struct Edge{int num,ne,c,len;}e[En];
int p[V],K;
void add(int x,int y,int z,int c)
{
    e[K].num=y;e[K].len=z;e[K].c=c;
    e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].len=-z;e[K].c=0;
    e[K].ne=p[y];p[y]=K++;
}
int N,st,ed,q[V],d[V],vis[V],pre[V];
bool spfa()
{
    int i,j,k,top=0,tail=1;
    for(i=0;i<N;i++)
    {vis[i]=0;d[i]=oo;}
    vis[st]=1;d[st]=0;q[1]=st;
    while(top!=tail)
    {
        top=(top+1)%V;
        i=q[top];vis[i]=0;
        for(j=p[i];j!=-1;j=e[j].ne)
        {
            k=e[j].num;
            if(e[j].c&&d[k]-e[j].len>d[i])
            {
                d[k]=e[j].len+d[i];pre[k]=j;
                if(!vis[k])
                {
                    vis[k]=1;
                    tail=(tail+1)%V;
                    q[tail]=k;
                }
            }
        }
    }
    if(d[ed]==oo)return false;
    return true;
}
int mcmf()
{
    int ret=0;
    while(spfa())
    {
        int u=ed,mi=oo;
        while(u!=st)
        {
            mi=min(mi,e[pre[u]].c);
            u=e[pre[u]^1].num;
        }
        ret+=d[ed]*mi;
        u=ed;
        while(u!=st)
        {
            e[pre[u]].c-=mi;
            e[pre[u]^1].c+=mi;
            u=e[pre[u]^1].num;
        }
    }
    return ret;
}
int a[300],cover[300],dn[300],less[300];
int pr[300],ne[300],exs[300],ext[300],eq[102];
int X[En],Y[En],C;
int i,j,S,T,n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(cover,0,sizeof(cover));
        memset(dn,0,sizeof(dn));
        int cost=0;
        for(i=1;i<=n;i++)
        {
            if(dn[i])continue;
            S=i;
            for(j=a[i];j;j-=j&-j)cost++;
            for(j=i;j<=n;j++)
            {
                if(a[j]==a[S])
                {
                    dn[j]=1;
                    T=j;
                }
            }
            for(j=S;j<=T;j++)cover[j]++;
        }
        for(i=1;i<=n;i++)less[i]=max(0,cover[i]-m);
        N=n+1;st=0;ed=n;
        for(i=0;i<N;i++)p[i]=-1;K=0;
        for(i=1;i<=n;i++)
        add(i-1,i,0,U-less[i]);
        int en=0;
        memset(pr,-1,sizeof(pr));
        memset(ne,-1,sizeof(ne));
        for(i=1;i<=n;i++)
        {
            int id=-1;
            for(j=i+1;j<=n;j++)
            if(a[j]==a[i]){id=j;break;}
            if(id==-1)continue;
            int tc=0;
            for(j=a[i];j;j-=j&-j)tc++;
            add(i,id-1,tc,1);
            pr[id]=en;ne[i]=en;
            exs[en]=i;exs[en++]=id;
        }
        int ret=mcmf()+cost;
    //  cout<<ret<<endl;
        for(i=0;i<m;i++)eq[i]=-1;C=0;
        for(i=1;i<=n;i++)
        {
            int id;
            if(pr[i]==-1)
            {
                for(j=0;j<m;j++)
                if(eq[j]==-1)
                {
                    eq[j]=a[i];
                    Y[C]=j;X[C++]=a[i];
                    id=j;
                    break;
                }
            }
            else
            {
                if(e[2*n+2*pr[i]].c==0)
                {
                    id=-1;
                    for(j=0;j<m;j++)
                    if(eq[j]==-1)
                    {
                        eq[j]=a[i];
                        Y[C]=j;X[C++]=a[i];
                        id=j;
                        break;
                    }
                //  printf("OK %d %d\n",i,id);
                }
                else
                {
                    for(j=0;j<m;j++)
                    if(eq[j]==a[i])
                    {
                        id=j;
                        break;
                    }
                }
            }
            X[C]=-1;Y[C++]=id;
            if(ne[i]!=-1)
            {
                if(e[2*n+2*ne[i]].c==0)
                {
                    for(j=0;j<m;j++)
                    if(eq[j]==a[i])
                    {
                        eq[j]=-1;break;
                    }
                }
            }
            else
            {
                for(j=0;j<m;j++)
                    if(eq[j]==a[i])
                    {
                        eq[j]=-1;break;
                    }
            }
        }
        printf("%d %d\n",C,ret);
        for(i=0;i<C;i++)
        {
            if(X[i]!=-1)printf("%c=%d\n",Y[i]+'a',X[i]);
            else printf("print(%c)\n",Y[i]+'a');
        }
    }
}