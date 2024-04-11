#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 100010
int f0[2][N],*f,*g;int a[330],n,fa[330],ga[330],m,t;bool v[330];
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)fa[i]=ga[i]=-1;
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),fa[x]=y,ga[y]=x;
    for(int i=1;i<=n;i++)if(ga[i]==-1)
    {
        int S=0;
        for(int x=i;x!=-1;x=fa[x])
            a[x]+=S,S=a[x],v[x]=1;
    }
    for(int i=1;i<=n;i++)if(!v[i]){puts("0");return 0;}
    //for(int i=1;i<=n;i++)printf("%d\n",a[i]);
    f=f0[0];f[0]=1;
    g=f0[1];
    for(int i=1;i<=n;i++)
        if(fa[i]==-1)
        {
            for(int j=0;j<=t-a[i];j++)
                (f[j+a[i]]+=f[j])%=P;
        }else
        {
            memset(g,0,(sizeof(int))*(t+1));
            for(int j=0;j<=t-a[i];j++)
                (((g[j+a[i]]+=g[j])%=P)+=f[j])%=P;
            swap(f,g);
        }
    printf("%d\n",f[t]);
    return 0;
}