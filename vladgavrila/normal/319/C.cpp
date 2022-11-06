#include <cstdio>
#include <iostream>

using namespace std;

#define maxn 100010

int n, m, st0, pz;
long long a[maxn], b[maxn];
long long st[maxn], bb[maxn];
double ti[maxn];
long long d[maxn];

long long f(int a, int pz)
{
    return 1LL*a*st[pz]+bb[pz];
}

double intersect(int x, int y)
{
    return (double(bb[y]-bb[x]))/(st[x]-st[y]);
}

int main()
{
  //  freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    for(int i=1; i<=n; ++i)
        scanf("%d", &b[i]);

    st[++st0]=b[1];

    pz=1;
    for(int i=2; i<=n; ++i)
    {
        while(pz>st0)
            --pz;
        while(pz<st0 && f(a[i], pz)>f(a[i], pz+1))
            ++pz;

        d[i]=f(a[i], pz);

        st[++st0]=b[i];
        bb[st0]=d[i];
        ti[st0]=intersect(st0-1, st0);

        while(st0>1 && ti[st0]<ti[st0-1])
        {
            st[st0-1]=st[st0];
            bb[st0-1]=bb[st0];
            --st0;
            ti[st0]=intersect(st0-1, st0);
        }
    }

    cout<<d[n]<<"\n";

    return 0;
}