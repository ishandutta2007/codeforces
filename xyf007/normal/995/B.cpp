#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, a[201];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        for (int j = i + 1; j <= 2 * n; j++)
        {
            if (a[i] == a[j])
            {
                while (j > i + 1)
                {
                    std::swap(a[j], a[j - 1]);
                    j--;
                    ans++;
                }
                break;
            }
        }
    }
    std::cout << ans;
    return 0;
}