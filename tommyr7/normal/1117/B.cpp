#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,k,m,a[Maxn];
long long ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ans=1LL*a[n-1]*(m/(k+1))+1LL*a[n]*(m-(m/(k+1)));
    printf("%lld\n",ans);
    return 0;
}