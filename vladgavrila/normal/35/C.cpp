#include <stdio.h>

using namespace std;

#define maxn 2010

int n, m, a, b, i, j, k, left, xx, yy, right, sa, sb, cx[maxn*maxn], cy[maxn*maxn];
int v[maxn][maxn];
const int d1[]={0, 0, -1, 1};
const int d2[]={1, -1, 0, 0};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; ++i)
    {
        scanf("%d%d", &a, &b);
        cx[++right]=a;
        cy[right]=b;
        v[a][b]=1;
    }
    sa=1;
    sb=1;
    for(int i=1; i<=right; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            xx=cx[i]+d1[j];
            yy=cy[i]+d2[j];
            if(xx>0 && xx<=n && yy>0 && yy<=m && v[xx][yy]==0)
            {
                cx[++right]=xx;
                cy[right]=yy;
                v[xx][yy]=v[cx[i]][cy[i]]+1;
                if(v[sa][sb]<v[xx][yy])
                {
                    sa=xx;
                    sb=yy;
                }
            }
        }
    }

    printf("%d %d\n", sa, sb);
    return 0;
}