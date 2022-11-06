#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, x, pz, sol, a[maxn], b[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &x);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i)
        scanf("%d", &b[i]);

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    pz=n;

    for(int i=1; i<=n; ++i)
    {
        if(a[i]+b[pz]>=x)
        {
            --pz;
            ++sol;
        }
    }

    printf("1 %d\n", sol);

    return 0;
}