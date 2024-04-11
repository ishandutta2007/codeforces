#include <bits/stdc++.h>
#define Maxn 50007
using namespace std;
int n;
int a[Maxn];
int ans=0,sum=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ans+=a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<=a[i];j++)
            if (a[i]%j==0) ans=min(ans,sum-a[1]-a[i]+a[1]*j+a[i]/j);
    }
    printf("%d\n",ans);
    return 0;
}