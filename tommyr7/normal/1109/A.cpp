#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n;
int a[Maxn];
map<int,int> mp1,mp2;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    mp1.clear();
    mp2.clear();
    ++mp2[0];
    long long ans=0LL;
    int now=0;
    for (int i=1;i<=n;i++)
    {
        now^=a[i];
        if (i%2)
        {
            ans+=mp1[now];
            ++mp1[now];
        } else
        {
            ans+=mp2[now];
            ++mp2[now];
        }
    }
    printf("%lld\n",ans);
    return 0;
}