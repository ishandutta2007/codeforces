#include <bits/stdc++.h>
#define Maxn 1007
int cnt=0;
int ans[Maxn],a[Maxn];
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=n;i;i--)
        a[i]-=a[i-1];
    for (int i=1;i<=n;i++)
    {
        bool flag=true;
        for (int j=i+1;j<=n;j++)
            if (a[j]!=a[j-i]) flag=false;
        if (flag) ans[++cnt]=i;
    }
    printf("%d\n",cnt);
    for (int i=1;i<=cnt;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}