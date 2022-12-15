#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200010
int he[N],ne[N*2],ad[N*2],d[N],n,m,st[N],le[N],bl[N],w[N],a[N],L,S1;
int f[N*2],g[N];
void addE(int x,int y)
{
    static int t=0;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y;
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x;
}
inline int lb(int x){return x&(x^(x-1));}
void add(int *f,int n,int x,int y)
{
    x=n-x+1;
    while(x<=n)f[x]+=y,x+=lb(x);
}
int ask(int *f,int n,int x)
{
    x=n-x+1;
    int S=0;
    while(x>0)S+=f[x],x-=lb(x);
    return S;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),addE(x,y);
    int la=0;
    for(int p=he[1];p;p=ne[p])
    {
        int c=ad[p];
        st[L]=la;bl[c]=L,w[c]=la,a[la++]=c;le[L]=1;
        int law=1;
        while(true)
        {
            bool F=1;
            for(int p=he[c];p;p=ne[p])
                if(ad[p]!=law)
                {
                    int d=ad[p];law=c;c=d;
                    le[L]++;w[c]=la,a[la++]=c;bl[c]=L;
                    F=0;
                    break;
                }
            if(F)break;
        }
        L++;la++;
    }
    for(int i=2;i<=n;i++)d[i]=w[i]-st[bl[i]]+1;
    //for(int i=1;i<=n;i++)printf("%d %d\n",i,d[i]);
    /*
    for(int i=0;i<L;i++)
        for(int j=st[i];j<st[i]+le[i];j++)
            printf("%d%c",a[j],j==st[i]+le[i]-1?'\n':' ');
    */
    while(m--)
    {
        int z;scanf("%d",&z);
        if(z==0)
        {
            int x,y;scanf("%d%d%d",&x,&y,&z);
            if(z>=d[x])S1+=y;
            if(z>d[x])add(g,n,z-d[x],y);
            int l=max(d[x]-z,1),r=min(d[x]+z,le[bl[x]]);
            add(f+st[bl[x]],le[bl[x]],l-1,-y);
            add(f+st[bl[x]],le[bl[x]],r,y);
            if(z>d[x])add(f+st[bl[x]],le[bl[x]],min(z-d[x],le[bl[x]]),-y);
        }else
        if(z==1)
        {
            int x;scanf("%d",&x);
            if(x==1){printf("%d\n",S1);continue;}
            printf("%d\n",ask(g,n,d[x])+ask(f+st[bl[x]],le[bl[x]],d[x]));
        }
    }
    return 0;
}