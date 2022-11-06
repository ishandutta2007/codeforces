#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 120

int n, i, j, k, ok;
int v[maxn];

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
    }
    sort(v+1, v+n+1);
    for(int i=1; i<=n; i+=2)
    {
        if(v[i]<0 && v[i+1]<0)
        {
            ok=1;
            printf("%d %d ", v[i], v[i+1]);
        }
    }
    for(int i=1; i<=n; ++i)
        if(v[i]>0)
        {
            ok=1;
            printf("%d ", v[i]);
        }
    if(!ok)
        printf("%d ", v[n]);
    printf("\n");
    return 0;
}