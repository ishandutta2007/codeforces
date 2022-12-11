#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,k;
int a[Maxn],b[Maxn];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<n;i++)
        b[i]=a[i+1]-a[i];
    sort(b+1,b+n);
    long long ans=k;
    for (int i=1;i<=n-k;i++)
        ans+=b[i];
    printf("%lld\n",ans);
    return 0;
}