#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 10010

int n, i, j, k, x, nr;
int v[maxn];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        v[i]*=(n-i+1);
    }
    sort(v+1, v+n+1);
    for(int i=1; i<=n && x-v[i]>=0; ++i)
    {
        x-=v[i];
        nr++;
    }
    printf("%d\n", nr);
    return 0;
}