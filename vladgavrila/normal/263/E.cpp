#include <cstdio>

using namespace std;

#define maxn 2010

int n, m, k, a, b;
long long v[maxn][maxn];
long long mx, cr;

inline long long aria(int a, int b, int c, int d)
{
    return v[c][d]+v[a-1][b-1]-v[c][b-1]-v[a-1][d];
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            scanf("%d", &v[i+j-1][i-j+m]);

    for(int i=1; i<=n+m; ++i)
        for(int j=1; j<=n+m; ++j)
            v[i][j]+=v[i][j-1];

    for(int i=1; i<=n+m; ++i)
        for(int j=1; j<=n+m; ++j)
            v[i][j]+=v[i-1][j];

    mx=-1;

    for(int i=k; i<=n-k+1; ++i)
        for(int j=k; j<=m-k+1; ++j)
        {
            cr=0;
            for(int l=0; l<k; ++l)
                cr+=aria(i+j-1-l, i-j+m-l, i+j-1+l, i-j+m+l);
            if(cr>mx)
            {
                mx=cr;
                a=i;
                b=j;
            }
        }

    printf("%d %d\n", a, b);

    return 0;
}