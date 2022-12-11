#include <bits/stdc++.h>
using namespace std;
#define Maxn 2007
int n,x[Maxn],y[Maxn];
int calc(int x)
{
    if (x%2==0) return x/2;
    return (x+1)/2;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    while (true)
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
            if ((x[i]+y[i])%2==0) ++cnt;
        if (cnt!=0&&cnt!=n)
        {
            printf("%d\n",cnt);
            for (int i=1;i<=n;i++)
                if ((x[i]+y[i])%2==0) printf("%d ",i);
            printf("\n");
            return 0;
        }
        else
        {
            cnt=0;
            for (int i=1;i<=n;i++)
                if (x[i]%2==0) ++cnt;
            if (cnt!=0&&cnt!=n)
            {
                printf("%d\n",cnt);
                for (int i=1;i<=n;i++)
                    if (x[i]%2==0) printf("%d ",i);
                printf("\n");
                return 0;
            }
        }
        for (int i=1;i<=n;i++)
            x[i]=calc(x[i]),y[i]=calc(y[i]);
    }
    return 0;
}