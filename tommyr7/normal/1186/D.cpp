#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int a[Maxn];
double x[Maxn];
int main()
{
    scanf("%d",&n);
    long long sum=0LL;
    for (int i=1;i<=n;i++)
    {
        scanf("%lf",&x[i]);
        a[i]=trunc(x[i]);
        if (1.0*a[i]>x[i]) --a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;i++)
        if (sum<0LL&&1.0*a[i]!=x[i])
        {
            ++sum;
            ++a[i];
        }
    for (int i=1;i<=n;i++)
        printf("%d\n",a[i]);
    return 0;
}