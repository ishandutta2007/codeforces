#include <bits/stdc++.h>
using namespace std;
int n,m;
#define Maxn 200007
int a[Maxn];
long long pos[Maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    long long s=0LL;
    for (int i=1;i<=m;i++)
        s+=a[i];
    if (s<n) printf("%d\n",-1);
    else
    {
        pos[1]=1LL;
        long long now=1LL;
        for (int i=2;i<=m;i++)
        {
            now=max(now+1,n+1-s+a[i-1]);
            pos[i]=now;
            s-=a[i-1];
        }
        bool check=true;
        for (int i=1;i<=m;i++)
            if (pos[i]<1||pos[i]>n+1-a[i]) check=false;
        if (!check) printf("%d\n",-1);
        else
        {
            for (int i=1;i<=m;i++)
                printf("%lld ",pos[i]);
            printf("\n");
        }
    }
    return 0;
}