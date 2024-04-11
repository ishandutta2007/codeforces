#include<cstring>
#include<cstdio>
const int modulo = 1000000007;
int dp[1002][20002], mn, mx, s[20002], t[20002], a[1002], n, ans;
void inc(int & a, const int & b)
{
    a = a + b;
    if(a > modulo) a -= modulo;
}
int _(const int & b)
{
    if(b < -10000 or b > 10000) return 0;
    else return b + 10001;
}
void calc(int le, int ri)
{
    if(le == ri) return;
    int mid = (le + ri) / 2;
    calc(le, mid);
    calc(mid + 1, ri);
    mn = -a[mid + 1];
    mx = -mn;
    for(int i = mn + 1; i < mx; i++) dp[mid + 1][_(i)] = 0;
    //for(int i = le; i <= ri; i++) for(int j = -4; j <= 4; j++) printf("dp[%d][%d] = %d\n", i, j, dp[i][_(j)]);
    dp[mid + 1][_(mn)] = dp[mid + 1][_(mx)] = 1;
    //for(int i = le; i <= ri; i++) for(int j = -4; j <= 4; j++) printf("dp[%d][%d] = %d\n", i, j, dp[i][_(j)]);
    for(int i = -10000; i <= 10000; i++) s[_(i)] = 0;
    for(int i = mid + 1; i <= ri; i++)
    {
        for(int j = mn - a[i + 1]; j <= mx + a[i + 1]; j++) dp[i + 1][_(j)] = 0;
        for(int j = mn; j <= mx; j++) inc(dp[i + 1][_(j + a[i + 1])], dp[i][_(j)]), inc(dp[i + 1][_(j - a[i + 1])], dp[i][_(j)]), inc(s[_(j)], dp[i][_(j)]);
        mn -= a[i + 1]; mx += a[i + 1];
    }
    //for(int i = le; i <= ri; i++) for(int j = -4; j <= 4; j++) printf("dp[%d][%d] = %d\n", i, j, dp[i][_(j)]);
    
    mn = -a[mid];
    mx = -mn;
    for(int i = mn + 1; i < mx; i++) dp[mid][_(i)] = 0;
    dp[mid][_(mn)] = dp[mid][_(mx)] = 1;
    for(int i = -10000; i <= 10000; i++) t[_(i)] = 0;
    for(int i = mid; i >= le; i--)
    {
        for(int j = mn - a[i - 1]; j <= mx + a[i - 1]; j++) dp[i - 1][_(j)] = 0;
        for(int j = mn; j <= mx; j++) inc(dp[i - 1][_(j + a[i - 1])], dp[i][_(j)]), inc(dp[i - 1][_(j - a[i - 1])], dp[i][_(j)]), inc(t[_(j)], dp[i][_(j)]);
        mn -= a[i - 1]; mx += a[i - 1];
    }
    for(int i = -10000; i <= 10000; i++) inc(ans, (int)((long long)s[_(i)] * t[_(-i)] % modulo));
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ans = 0;
    calc(1, n);
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}