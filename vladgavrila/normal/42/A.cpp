#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 101

int n, i, j, k, vol;
int a[maxn], b[maxn];
double sol, val;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &vol);
    sol=1000000000;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &b[i]);
        sol=min((double)b[i]/a[i], sol);
    }
    for(int i=1; i<=n; ++i)
    {
        val=val+sol*a[i];
    }
    val=min(val, double(vol));
    printf("%.5lf\n", val);
    return 0;
}