#include <bits/stdc++.h>
#define Maxn 2007
using namespace std;
int n,a[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    int sum1=0,sum2=0;
    for (int i=1;i<=n;i++)
        sum1+=a[i];
    for (int i=n+1;i<=2*n;i++)
        sum2+=a[i];
    if (sum1==sum2) printf("%d\n",-1); else
    {
        for (int i=1;i<=2*n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}