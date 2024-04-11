#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,x,y,k;
int a[Maxn],b[Maxn];
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    if (k>=n||k>=m)
    {
        printf("%d\n",-1);
        return 0;
    }
    int ans=0;
    int j=1;
    for (int i=0;i<=k;i++)
    {
        int now=a[i+1]+x;
        while (j<=m&&b[j]<now) ++j;
        if (j+k-i>m)
        {
            printf("%d\n",-1);
            return 0;
        }
        ans=max(ans,b[j+k-i]+y);
    }
    printf("%d\n",ans);
    return 0;
}