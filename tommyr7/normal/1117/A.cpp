#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int a[Maxn],n,mx;
int ans,now;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    for (int i=1;i<=n;i++)
        if (a[i]==mx) ++now; else
        {
            ans=max(ans,now);
            now=0;
        }
    ans=max(ans,now);
    printf("%d\n",ans);
    return 0;
}