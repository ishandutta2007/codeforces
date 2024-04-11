#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int n, le, ri, x[21], y[21];
double a[21];
double dp[1048576];
double calc(double len, int id)
{
    double alpha = atan2(-y[id], -x[id] + len);
    alpha += a[id];
    if (alpha + 1e-8 > 0) return ri;
    return x[id] - y[id] / tan(alpha);
}
int main()
{
    scanf("%d%d%d", &n, &le, &ri);
    for(int i = 0; i < n; i++) scanf("%d%d%lf", &x[i], &y[i], &a[i]);
    for(int i = 0; i < n; i++) a[i] = a[i] / 180 * 3.141592653589793238;
    for(int i = 0; i < 1 << n; i++) dp[i] = le;
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++) if(i & 1 << j)
        {
            dp[i] = max(dp[i], calc(dp[i - (1 << j)], j));
        }
    }
    printf("%.6f\n", min((double)ri, dp[(1 << n) - 1]) - le);
    fclose(stdin);
    return 0;
}