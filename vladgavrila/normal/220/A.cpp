#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, df;
int o[maxn], v[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &o[i]);
        v[i]=o[i];
    }

    sort(v+1, v+n+1);

    for(int i=1; i<=n; ++i)
    {
        if(o[i]!=v[i])
            ++df;
    }

    if(df<=2)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}