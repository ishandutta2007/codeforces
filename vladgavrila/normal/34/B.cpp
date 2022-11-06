#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, i, j, k, m, sum, v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
    }
    sort(v+1, v+n+1);
    for(int i=1; i<=m && v[i]<=0; ++i)
        sum-=v[i];
    sum=max(sum, 0);
    printf("%d\n", sum);
    return 0;
}