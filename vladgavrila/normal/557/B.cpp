#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 200010

int n, w;
int v[maxn];

int main()
{
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);

    scanf("%d%d", &n, &w);
    for(int i=1; i<=2*n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+2*n+1);

    double sol = min(1LL*w*2, min(1LL*v[1]*2, 1LL*v[n+1])*3*n);

    printf("%.6lf\n", sol/2);

    return 0;
}