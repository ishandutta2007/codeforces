#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010
#define inf (1LL*1000000000*1000000000)

int n, m, st;
int v[maxn];
long long d[maxn];
int a[maxn], b[maxn];

int main()
{
  //  freopen("f.in", "r", stdin);
    scanf("%d%d", &n, &v[1]);
    st=v[1];
    m=1;

    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        v[++m]=a[i]; v[++m]=b[i];
    }

    sort(v+1, v+m+1);

    for(int i=1; i<=m; ++i)
    {
        if(v[i]==st)
            d[i]=0;
        else
            d[i]=inf;
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=2; j<=m; ++j)
            d[j]=min(d[j], d[j-1]+v[j]-v[j-1]);
        for(int j=m-1; j>0; --j)
            d[j]=min(d[j], d[j+1]+v[j+1]-v[j]);

        for(int j=1; j<=m; ++j)
        {
            if(v[j]<a[i])
                d[j]+=a[i]-v[j];
            if(v[j]>b[i])
                d[j]+=v[j]-b[i];
        }
    }

    long long sol=inf;

    for(int i=1; i<=m; ++i)
        sol=min(sol, d[i]);

    printf("%I64d\n", sol);

    return 0;
}