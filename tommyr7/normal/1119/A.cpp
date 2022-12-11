#include <bits/stdc++.h>
#define Maxn 500007
using namespace std;
int n;
int a[Maxn];
int ans=1;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=2;i<=n;i++)
        if (a[1]!=a[i]) ans=max(ans,i-1);
    for (int i=1;i<n;i++)
        if (a[i]!=a[n]) ans=max(ans,n-i);
    printf("%d\n",ans);
    return 0;
}