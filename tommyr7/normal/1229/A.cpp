#include <bits/stdc++.h>
using namespace std;
#define Maxn 7007
long long a[Maxn],b[Maxn],c[Maxn];
int tot[Maxn];
map<long long,int> mp;
int n,m=0;
long long ans=0LL;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ++mp[a[i]];
    }
    for (int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for (int i=1;i<=n;i++)
        tot[i]=mp[a[i]];
    for (int i=1;i<=n;i++)
        if (tot[i]>1) ans+=b[i];
    for (int i=1;i<=n;i++)
        if (tot[i]==1)
        {
            bool flag=false;
            for (int j=1;j<=n;j++)
                if (tot[j]>1&&((a[i]&a[j])==a[i])) flag=true;
            if (flag) ans+=b[i];
        }
    printf("%lld\n",ans);
    return 0;
}