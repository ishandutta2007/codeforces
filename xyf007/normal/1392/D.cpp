#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
char s[400005];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++)
        {
            s[i + n] = s[i];
        }
        int tmp = 1;
        while (tmp <= n && s[tmp] == s[tmp + 1])
        {
            tmp++;
        }
        if (tmp > n)
        {
            printf("%d\n", (n - 1) / 3 + 1);
            continue;
        }
        int S = tmp + 1, T = S + n - 1, ans = 0, cnt = 1;
        for (int i = S + 1; i <= T; i++)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                ans += cnt / 3;
                cnt = 1;
            }
        }
        ans += cnt / 3;
        printf("%d\n", ans);
    }
    return 0;
}