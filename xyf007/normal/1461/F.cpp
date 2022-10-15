#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, a[100001], tmp[21], pre[21], cnt;
char op[4], ans[100001];
long long dp[21], mul[100001];
bool vis[3];
void Solve(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    for (int i = l; i <= r; i++)
    {
        if (!a[i])
        {
            ans[i - 1] = ans[i] = '+';
            Solve(l, i - 1);
            Solve(i + 1, r);
            return;
        }
    }
    while (l < r && a[l] == 1)
    {
        ans[l++] = '+';
    }
    while (l < r && a[r] == 1)
    {
        ans[--r] = '+';
    }
    if (l == r)
    {
        return;
    }
    memset(dp, 0xcf, sizeof(dp));
    dp[0] = 0;
    mul[l - 1] = 1LL;
    tmp[0] = l - 1;
    long long sum = 1;
    cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (a[i] != 1)
        {
            tmp[++cnt] = i;
            sum *= a[i];
            if (sum > n)
            {
                for (int i = l; i < r; i++)
                {
                    ans[i] = '*';
                }
                return;
            }
        }
    }
    for (int i = l; i <= r; i++)
    {
        mul[i] = mul[i - 1] * a[i];
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long ttt = dp[j] + tmp[j + 1] - 1 - tmp[j] + mul[tmp[i]] / mul[tmp[j]];
            if (dp[i] < ttt)
            {
                dp[i] = ttt;
                pre[i] = j;
            }
        }
    }
    int now = cnt;
    while (now)
    {
        int p = pre[now];
        if (p)
        {
            for (int i = tmp[p]; i < tmp[p + 1]; i++)
            {
                ans[i] = '+';
            }
        }
        for (int i = tmp[p + 1]; i < tmp[now]; i++)
        {
            ans[i] = '*';
        }
        now = p;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> op;
    for (size_t i = 0; i < strlen(op); i++)
    {
        if (op[i] == '+')
        {
            vis[0] = true;
        }
        else if (op[i] == '-')
        {
            vis[1] = true;
        }
        else
        {
            vis[2] = true;
        }
    }
    if (!vis[2])
    {
        for (int i = 1; i < n; i++)
        {
            std::cout << a[i] << (vis[0] ? '+' : '-');
        }
        std::cout << a[n];
        return 0;
    }
    if (!vis[0])
    {
        if (vis[1])
        {
            bool f = false;
            std::cout << a[1];
            for (int i = 2; i <= n; i++)
            {
                if (f)
                {
                    std::cout << '*' << a[i];
                    continue;
                }
                if (!a[i])
                {
                    std::cout << "-0";
                    f = true;
                }
                else
                {
                    std::cout << '*' << a[i];
                }
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                std::cout << a[i] << '*';
            }
            std::cout << a[n];
        }
        return 0;
    }
    Solve(1, n);
    for (int i = 1; i < n; i++)
    {
        std::cout << a[i] << ans[i];
    }
    std::cout << a[n];
    return 0;
}