#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[10000005];
long long x, y;
long long D(int n)
{
    if (n<=0) return 0;
    if (n==1) return x;
    if (!dp[n])
    {
        if(n%2) dp[n]=min(D(n-1),D(n+1))+x;
        else
        {
            int s=n/2;
            if (s*x<=y) dp[n]=n*x;
            else dp[n]=D(n/2)+y;
        }
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d%lld%lld",&n,&x,&y);
    printf("%lld",D(n));
}