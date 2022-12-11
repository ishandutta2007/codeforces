#include <bits/stdc++.h>
using namespace std;
#define Maxn 5000007
#define Maxm 200007
#define modp 1000000007
int n,m;
int p[Maxm],k[Maxm],b[Maxm],w[Maxm];
int a[Maxn],t[Maxn],ans[Maxn];
bool vis[Maxn];
int seed=0,base=0;
int rnd()
{
    int res=seed;
    seed=(1LL*seed*base+233)%1000000007;
    return res;
}
void init()
{
    p[0]=0;
    for (int i=1;i<=m;i++)
    {
        seed=b[i];
        base=w[i];
        for (int j=p[i-1]+1;j<=p[i];j++)
        {
            t[j]=(rnd()%2)+1;
            a[j]=(rnd()%k[i])+1;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d%d",&p[i],&k[i],&b[i],&w[i]);
    init();
    if (t[1]==2)
    {
        for (int i=1;i<=n;i++)
            t[i]=3-t[i];
    }
    long long sum1=0LL,sum2=0LL;
    for (int i=1;i<=n;i++)
        if (t[i]==1) sum1+=a[i]; else sum2+=a[i];
    if (sum1==sum2)
    {
        for (int i=1;i<=n;i++)
            ans[i]=a[i];
    }
    else if (sum1>sum2)
    {
        memset(vis,false,sizeof(vis));
        for (int i=1;i<=n;i++)
            if (t[i]==2) ans[i]=a[i]; else ans[i]=0;
        long long del=1LL;
        int op=1,pos=1;
        long long k=0;
        while (del>0||k<=n)
        {
            ++k;
            if (t[pos]==op)
            {
                long long tmp=min(del,1LL*a[pos]);
                del-=tmp;
                ans[pos]+=tmp;
                a[pos]-=tmp;
            }
            else if (!vis[pos]) 
            {
                vis[pos]=true;
                del+=a[pos];
            }
            ++pos;
            if (pos>n) pos=1;
        }
    }
    else
    {
        memset(vis,false,sizeof(vis));
        for (int i=1;i<=n;i++)
            if (t[i]==1) ans[i]=a[i]; else ans[i]=0;
        long long del=1LL;
        --a[1];
        int op=2,pos=1;
        while (t[pos]!=op) ++pos;
        long long k=0;
        while (del>0||k<=n)
        {
            ++k;
            if (t[pos]==op)
            {
                long long tmp=min(del,1LL*a[pos]);
                del-=tmp;
                ans[pos]+=tmp;
                a[pos]-=tmp;
            }
            else if (!vis[pos]) 
            {
                vis[pos]=true;
                del+=a[pos];
            }
            ++pos;
            if (pos>n) pos=1;
        }
    }
    long long anss=1LL;
    for (int i=1;i<=n;i++)
        anss=(1LL*anss*((((1LL*ans[i])^(1LL*i*i))+1)%modp))%modp;
    printf("%lld\n",anss);
    return 0;
}