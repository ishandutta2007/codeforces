#include <cstdio>

using namespace std;

#define maxn 1010

int n, k, sol;
int v[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<=n; ++i)
        if(v[i]>=v[k] && v[i]>0)
            ++sol;

    printf("%d\n", sol);

    return 0;
}