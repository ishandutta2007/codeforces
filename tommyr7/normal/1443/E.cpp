#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,q,k;
long long id=1LL;
int a[Maxn],que[Maxn];
bool flag[Maxn];
long long val[Maxn];
long long calc(int x)
{
    return (1LL*x*(x+1))/2;
}
int main()
{
    val[0]=1;
    for (int i=1;i<=15;i++)
        val[i]=1LL*i*val[i-1];
    scanf("%d%d",&n,&q);
    k=min(15,n);
    for (int i=1;i<=n;i++)
        a[i]=i;
    while (q--)
    {
        int op;
        scanf("%d",&op);
        if (op==1)
        {
            int lx,rx;
            scanf("%d%d",&lx,&rx);
            if (rx<=n-k) printf("%lld\n",calc(rx)-calc(lx-1));
            else if (lx>n-k)
            {
                long long sum=0LL;
                for (int i=lx;i<=rx;i++)
                    sum+=a[i];
                printf("%lld\n",sum);
            } else
            {
                long long sum=calc(n-k)-calc(lx-1);
                for (int i=n-k+1;i<=rx;i++)
                    sum+=a[i];
                printf("%lld\n",sum);
            }
        } else
        {
            int x;
            scanf("%d",&x);
            id+=x;
            long long idx=id;
            for (int i=1;i<=k;i++)
                que[i]=n-k+i,flag[i]=true;
            for (int i=n-k+1;i<=n;i++)
            {
                int now=(idx-1)/val[n-i]+1;
                idx-=1LL*(now-1)*val[n-i];
                for (int j=1;j<=k;j++)
                {
                    if (flag[j]) --now;
                    if (now==0)
                    {
                        a[i]=que[j];
                        flag[j]=false;
                        break;
                    }
                }
            }
        }
    }
}