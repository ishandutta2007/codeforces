#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, m, q, p1, p2;
int wa[maxn], wb[maxn];
int v[maxn][maxn];
char c;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            scanf("%d", &v[i][j]);
    scanf("\n");

    for(int i=1; i<=n; ++i)
        wa[i]=i;
    for(int j=1; j<=m; ++j)
        wb[j]=j;

    while(q--)
    {
        scanf("%c%d%d\n", &c, &p1, &p2);

        if(c=='r')
            swap(wa[p1], wa[p2]);
        if(c=='c')
            swap(wb[p1], wb[p2]);
        if(c=='g')
            printf("%d\n", v[wa[p1]][wb[p2]]);
    }

    return 0;
}