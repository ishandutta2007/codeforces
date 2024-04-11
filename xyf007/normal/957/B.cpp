#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, m;
char a[101][101];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool f = 0;
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] == a[j][k] && a[i][k] == '#')
                {
                    f = 1;
                }
            }
            for (int k = 0; k < m; k++)
            {
                if (f && a[i][k] != a[j][k])
                {
                    printf("No");
                    return 0;
                }
            }
        }
    }
    printf("Yes");
    return 0;
}//ccc