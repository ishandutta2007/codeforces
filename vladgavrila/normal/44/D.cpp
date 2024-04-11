#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

#define maxn 5100

int n, i, j, k;
int a[maxn], b[maxn], c[maxn];
double sol;

int dist(int x, int y)
{
    return (a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y])+(c[x]-c[y])*(c[x]-c[y]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    sol=(double)2000000000;
    for(int i=1; i<=n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for(int i=2; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            sol=min(sol, sqrt(dist(1, i))+sqrt(dist(i, j))+sqrt(dist(1, j)));
    sol=sol/2;
    printf("%.6lf\n", sol);
    return 0;
}