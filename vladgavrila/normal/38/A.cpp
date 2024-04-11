#include <stdio.h>

using namespace std;

#define maxn 10010

int n, i, a, b, j, k;
int v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=2; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        v[i]+=v[i-1];
    }
    scanf("%d%d", &a, &b);
    printf("%d\n", v[b]-v[a]);
    return 0;
}