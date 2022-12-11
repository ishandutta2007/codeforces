#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n,a[Maxn];
int main()
{
    scanf("%d",&n);
    int cnt=0;
    for (int i=2;i<=n;i++)
    {
        int j=2;
        for (;j*j<=i;j++)
            if (i%j==0) break;
        if (j<i&&i%j==0) a[i]=a[j]; else a[i]=++cnt;
    }
    for (int i=2;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}