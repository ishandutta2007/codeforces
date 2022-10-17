#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=300010;
int n,m,a[N];
int x[N],y[N];
long long ans[N];
int head[1000],num[N],next[N],graphmr;
long long f[N+1000];
inline void add(int x,int y)
{
    int p=graphmr++;
    num[p]=y;next[p]=head[x];head[x]=p;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    memset(head,-1,sizeof head);
    int len=(int)sqrt(1.0*n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        if(y[i]>len)
        {
            for(int j=x[i];j<=n;j+=y[i])
                ans[i]+=a[j];
        }
        else add(y[i],i);
    }
    for(int i=1;i<=len;i++)
        if(head[i]!=-1)
        {
            for(int j=n;j>=1;j--) f[j]=f[j+i]+a[j];
            for(int j=head[i];~j;j=next[j])
                ans[num[j]]=f[x[num[j]]];
        }
    for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
    return 0;
}