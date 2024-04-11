#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m, a[100001], cnt[100001];
bool may[100001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] > 0)
        {
            cnt[a[i]]++;
        }
        else
        {
            cnt[-a[i]]--;
            tot++;
        }
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tot + cnt[i] == m)
        {
            may[i] = true;
            tmp++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            if (!may[a[i]])
            {
                std::cout << "Lie\n";
            }
            else if (tmp == 1)
            {
                std::cout << "Truth\n";
            }
            else
            {
                std::cout << "Not defined\n";
            }
        }
        else
        {
            if (!may[-a[i]])
            {
                std::cout << "Truth\n";
            }
            else if (tmp == 1)
            {
                std::cout << "Lie\n";
            }
            else
            {
                std::cout << "Not defined\n";
            }
        }
    }
    return 0;
}