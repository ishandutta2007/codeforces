#include <stdio.h>

using namespace std;

#define maxn 110

int n, i, j, kk, ok;
int a[maxn*maxn], b[maxn*maxn];
int f[maxn][maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        for(int j=i-1; j; --j)
        {
            ok=1;
            for(int k=1; k<i; ++k)
                if(f[i][k]==1 && f[j][k]==1)
                    ok=0;
            if(ok)
            {
                a[++kk]=j;
                b[kk]=i;
                f[j][i]=f[i][j]=1;
            }
        }
    }
    printf("%d\n", kk);
    for(int i=1; i<=kk; ++i)
    {
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}