#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 55

int n, m, p;
int v[maxn];
long long d[maxn][maxn][maxn];
double sol;
long long tp[maxn][maxn];

double dinamica()
{
    memset(d, 0, sizeof(d));

    d[0][0][0]=1;
    for(int i=0; i<p; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<=j; ++k)
            {
                d[i][j+1][k]+=d[i][j][k];
                if(i+v[j+1]<=p)
                    d[i+v[j+1]][j+1][k+1]+=d[i][j][k];
            }

    double rez=0, cr=0;

    for(int i=0; i+v[n]<=p; ++i)
        for(int k=0; k<n; ++k)
        {
            cr=d[i][n-1][k];
            for(int j=1; j<=k; ++j)
                cr*=j;
            for(int j=1; j<=n-k-1; ++j)
                cr*=j;
            for(int j=1; j<=n; ++j)
                cr/=j;
            rez=rez+cr;
        }

    return rez;
}




int main()
{
 //   freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    scanf("%d", &p);

    double sol=0;

    for(int i=1; i<=n; ++i)
    {
        swap(v[i], v[n]);
        sol+=dinamica();
        swap(v[i], v[n]);
    }

    printf("%.6lf\n", sol);

    return 0;
}