#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int Q, n, a[111111], mx;
long long sigma;
int main()
{
    scanf("%d", &n);
    mx = -0x7f7f7f7f;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
    sigma = 0;
    for(int i = 1; i <= n; i++) sigma += mx - a[i];
    if(sigma >= mx)
    {
        printf("%d\n", mx);
    }else
    {
        mx = mx - sigma;
        
        printf("%I64d\n", sigma + mx / (n - 1) * n + (mx % (n - 1) == 0?0:mx%(n - 1) + 1));
    }
    fclose(stdin);
    return 0;
}