#include <bits/stdc++.h>
using namespace std;
int n;
long long f[67];
int main()
{
    scanf("%d",&n);
    f[0]=1LL;
    for (int i=2;i<=n;i++)
        f[i]=2LL*f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}