#include <stdio.h>
#include <algorithm>

using namespace std;

int n, i, j, k, a, b, x1, y1, x2, y2, dist;

int ab(int a)
{
    if(a<0)
        return -a;
    return a;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);

    if(x1==0)
        a=y1;
    else
    if(y1==n)
        a=n+x1;
    else
    if(x1==n)
        a=n+n+n-y1;
    else
    if(y1==0)
        a=n+n+n+n-x1;

    if(x2==0)
        b=y2;
    else
    if(y2==n)
        b=n+x2;
    else
    if(x2==n)
        b=n+n+n-y2;
    else
    if(y2==0)
        b=n+n+n+n-x2;
    dist=min(ab(a-b), 4*n-ab(a-b));
    printf("%d\n", dist);
    return 0;
}