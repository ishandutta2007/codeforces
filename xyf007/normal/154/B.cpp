#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <bitset>
#include <vector>
int n, m, p[10001], tot, a[10001];
bool not_prime[100001];
std::bitset<10000> f[100001];
bool vis[100001];
std::vector<int> v[100001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    not_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            p[++tot] = i;
        }
        for (int j = 1; j <= tot && i * p[j] <= n; j++)
        {
            not_prime[i * p[j]] = true;
            if (!(i % p[j]))
            {
                break;
            }
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        for (int j = 1; j * p[i] <= n; j++)
        {
            f[j * p[i]].set(i);
            v[j * p[i]].emplace_back(i);
        }
    }
    std::bitset<10000> now;
    char op[10];
    int x;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> op >> x;
        if (op[0] == '+')
        {
            if (vis[x])
            {
                std::cout << "Already on\n";
                continue;
            }
            if ((f[x] & now).any())
            {
                for (auto &&j : v[x])
                {
                    if (a[j])
                    {
                        std::cout << "Conflict with " << a[j] << '\n';
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Success\n";
                vis[x] = true;
                now |= f[x];
                for (auto &&j : v[x])
                {
                    a[j] = x;
                }
            }
        }
        else
        {
            if (!vis[x])
            {
                std::cout << "Already off\n";
            }
            else
            {
                std::cout << "Success\n";
                vis[x] = false;
                now ^= f[x];
                for (auto &&j : v[x])
                {
                    a[j] = 0;
                }
            }
        }
    }
    return 0;
}