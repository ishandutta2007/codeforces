#include<cstring>
#include<cstdio>
int n, k, ans, ansi, sum, a[150001];
int main()
{
    scanf("%d%d", &n, &k);
    ansi = 1;
    ans = 0;
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    sum = ans;
    for(int i = k + 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        sum -= a[i - k];
        if(sum < ans)
        {
            ansi = i - k + 1;
            ans = sum;
        }
    }
    printf("%d\n", ansi);
}