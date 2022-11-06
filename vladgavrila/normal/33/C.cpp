#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, i, j, k, sol;
int v[maxn], sum[maxn], d1[maxn], d2[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1; i<=n; ++i)
        d1[i]=max(d1[i-1]+v[i], sum[i]*-1);
    for(int i=n; i; --i)
        d2[i]=max(d2[i+1]+v[i], (sum[n]-sum[i-1])*-1);
    for(int i=0; i<=n; ++i)
        sol=max(sol, d1[i]+d2[i+1]);
    printf("%d\n", sol);
    return 0;
}