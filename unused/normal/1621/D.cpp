#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <random>
#include <limits>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        long long a1 = 0;
        int a2 = 2e9;
        pair<int, int> t[] = {
            {0,         n},
            {0,         2 * n - 1},
            {n - 1,     n},
            {n - 1,     2 * n - 1},
            {n,         0},
            {2 * n - 1, 0},
            {n,         n - 1},
            {2 * n - 1, n - 1},
        };
        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                int x;
                scanf("%d",&x);

                if (i >= n && j >= n) a1 += x;
                else
                {
                    for (auto [y, z]: t)
                    {
                        if (y == i && z == j) a2 = min(a2, x);
                    }
                }
            }
        }
        printf("%lld\n", a1 + a2);
    }
}