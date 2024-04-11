#include<cstring>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<cmath>

#include<cstdlib>

#include<ctime>

#include<queue>

using namespace std;

int Q;
long long n, a[111111], s[111111], ans, d;
long long gcd(long long a, long long b)
{
    return b?gcd(b, a % b):a;
}

int main()

{

        scanf("%I64d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
        ans = s[n];
        for(int i = 1; i <= n; i++) ans += (s[n] - s[i]) - a[i] * (n - i) + a[i] * i - s[i];
        d = gcd(ans, n);
        printf("%I64d %I64d\n", ans / d, n / d);

    fclose(stdin);

    return 0;

}