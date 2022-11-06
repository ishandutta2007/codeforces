#include <cstdio>

using namespace std;

#define maxn 110
#define maxs 100010

int n, m;
double d[maxn][maxs];
int v[maxn];
int pl[maxn];

int main()
{

 //   freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d%d", &n, &m);
    if(m==1)
    {
        printf("1\n");
        return 0;
    }

    int tot = 0;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        tot+=v[i];
    }
    d[0][0]=1;
    for(int i=1; i<=n; ++i)
    {
        double csum=0;
        for(int j=1; j<=n*m; ++j)
        {
            csum = csum + d[i-1][j-1];
            if(j-m-1>=0)
                csum = csum - d[i-1][j-m-1];

            if(j-v[i]>=0)
                d[i][j]=(csum-d[i-1][j-v[i]])/(m-1);
            else
                d[i][j]=csum/(m-1);
        }

    }

    double sol=0.0;

    for(int i=0; i<tot; ++i)
        sol+=d[n][i];

    printf("%.11lf\n", double(sol*(m-1)+1));

    return 0;
}