#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 55

int n, m, nr;
int v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);

    for(int i=n; i; --i)
        for(int j=1; j<=i; ++j)
        {
            ++nr;
            printf("%d %d ", n-i+1, v[j]);
            for(int k=i+1; k<=n; ++k)
                printf("%d ", v[k]);
            printf("\n");
            if(nr==m)
                return 0;
        }

    return 0;
}