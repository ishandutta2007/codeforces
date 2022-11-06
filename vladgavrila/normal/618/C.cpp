#include <cstdio>

using namespace std;

#define maxn 100010

int n, m;
int x[maxn], y[maxn];

long long ab(long long x)
{
    if(x<0)
        return -x;
    return x;
}

long long det(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 1LL*x1*y2 + 1LL*x2*y3 + 1LL*x3*y1 - 1LL*x1*y3 - 1LL*x2*y1 - 1LL*x3*y2;
}

long long aria(int p1, int p2, int p3)
{
    return ab(det(x[p1], y[p1], x[p2], y[p2], x[p3], y[p3]));
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    int sa=1, sb=2, sc;

    for(int i=1; i<=n; ++i)
        if(aria(sa, sb, i) != 0)
            sc=i;

    for(int i=1; i<=n; ++i)
    {
        if(sa == i || sb == i || sc == i)
            continue;
        if(aria(sa, sb, i) + aria(sa, sc, i) + aria(sb, sc, i) == aria(sa, sb, sc))
        {
            if(aria(sa, sb, i)>0)
                sc=i;
            else
            if(aria(sa, sc, i)>0)
                sb=i;
            else
                sa=i;
        }
    }

    printf("%d %d %d\n", sa, sb, sc);

    return 0;
}