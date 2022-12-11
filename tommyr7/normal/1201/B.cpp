#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n;
long long a[Maxn];
int main()
{
    scanf("%d",&n);
    long long sum=0LL,tmp=0LL;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
        tmp=max(tmp,a[i]);
    }
    if (sum%2==0&&sum-tmp>=tmp) printf("YES\n"); else printf("NO\n");
    return 0;
}