#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 3010

int n, i, j, k, a, b;
long long sum[maxn], d[maxn];
pair<long long, long long> v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[i]=make_pair(a, b);
    }
    sort(v+1, v+n+1);
    d[1]=v[1].second;
    for(int i=1; i<=n+1; ++i)
        sum[i]=sum[i-1]+v[i].first;
  //  printf("%d ", d[1]);
    for(int i=2; i<=n+1; ++i)
    {
        d[i]=1LL*1000000*1000000000;
        for(int j=1; j<i; ++j)
            d[i]=min(d[i], d[j]+v[i].second+sum[i-1]-sum[j]-(1LL*i-j-1)*v[j].first);
   //     printf("%d ", d[i]);
    }
    printf("%d\n", d[n+1]);
    return 0;
}