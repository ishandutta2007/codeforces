#include <cstdio>

using namespace std;

#define maxn 100010

int n, k, sol, v[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    for(int i=k; i<n; ++i)
        if(v[i]!=v[i+1])
        {
            printf("-1\n");
            return 0;
        }

    for(int i=1; i<=k; ++i)
    {
        if(v[i]!=v[k])
            sol=i;
    }

    printf("%d\n", sol);


    return 0;
}