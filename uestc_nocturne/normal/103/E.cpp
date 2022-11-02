#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int V=610;
const int En=12000;
const LL ooo=100000000;
const LL oo=ooo*ooo;
struct Edge{int num,ne;LL c;}e[En];
int p[V],K;
void add(int x,int y,LL c)
{
    e[K].num=y;e[K].c=c;
    e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].c=0;
    e[K].ne=p[y];p[y]=K++;
}
int N,st,ed;
int d[V],gap[V],cur[V],pre[V];
LL low[V];
LL sap()
{
    LL ret=0;
    int i,u,v;
    bool fail;
    for(i=0;i<N;i++)
    {
        cur[i]=p[i];
        d[i]=0;gap[i]=0;
    }
    gap[0]=N;low[st]=oo;u=st;
    while(d[st]<N)
    {
        fail=true;
        for(i=cur[u];i!=-1;i=e[i].ne)
        {
            v=e[i].num;cur[u]=i;
            if(e[i].c&&d[u]==d[v]+1)
            {
                pre[v]=i;
                low[v]=min(low[u],e[i].c);u=v;
                if(u==ed)
                {
                    do
                    {
                        e[pre[u]].c-=low[ed];
                        e[pre[u]^1].c+=low[ed];
                        u=e[pre[u]^1].num;
                    }while(u!=st);
                    ret+=low[ed];
                }
                fail=false;break;
            }
        }
        if(fail)
        {
            gap[d[u]]--;
            if(!gap[d[u]])return ret;
            d[u]=N;
            for(i=p[u];i!=-1;i=e[i].ne)
            if(e[i].c)d[u]=min(d[u],d[e[i].num]+1);
            gap[d[u]]++;cur[u]=p[u];
            if(u!=st)u=e[pre[u]^1].num;
        }
    }
    return ret;
}
LL ans,S,w;
int x,y,i,j,co[V][V],n;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(co,0,sizeof(co));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(j=0;j<x;j++)
            {
                scanf("%d",&y);
                co[i][y]=1;
            }
        }
        N=2*n+2;st=0;ed=2*n+1;
        for(i=0;i<N;i++)p[i]=-1;K=0;S=0;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&w);
            if(w>0)add(i,ed,w);
            else
            {
                S-=w;
                add(st,i,-w);
            }
        }
        for(i=1;i<=n;i++)
        {
            add(st,i,ooo);
            add(i+n,ed,ooo);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(co[i][j])
                {
                    add(i,j+n,ooo);
                }
            }
        }
        ans=sap()-n*ooo-S;
        printf("%I64d\n",ans);
    }
}