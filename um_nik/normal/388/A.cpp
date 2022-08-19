#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;

int n;
int ans;
int x[200];
int y[200];

bool cmp (int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n, cmp);
    for (ans = 1; ans <= n; ans++)
    {
        for (int i = 0; i < ans; i++)
            y[i] = x[i];
        bool good = true;
        for (int i = ans; i < n; i++)
        {
            int max_v = -1;
            int tmp = -1;
            for (int j = 0; j < ans; j++)
            {
                if (y[j] > 0)
                {
                    if (y[j] > max_v)
                    {
                        max_v = y[j];
                        tmp = j;
                    }
                }
            }
            if (tmp == -1)
            {
                good = false;
                break;
            }
            y[tmp] = min(x[i], y[tmp] - 1);
        }
        if (good)
        {
            printf("%d\n", ans);
            return 0;
        }
    }
    return 0;
}