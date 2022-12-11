#pragma GCC target("popcnt")

#include <cctype>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int dp[10][1000005];

set<int> st;

int main()
{
    int a;
    scanf("%d",&a);
    dp[0][0] = 1;

    for (int i = 1; i <= 9; i++)
    {
        memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
        for (int j = 1 << (i - 1); j <= 1000000; j++)
        {
            dp[i][j] = min((int)1e9, dp[i][j] + dp[i][j - (1 << (i - 1))]);
            if (dp[i][j] == a)
            {
                printf("%d %d\n", j, i);
                for (int k = 0; k < i; k++) printf("%d ", 1 << k);
                printf("\n");
                return 0;
            }
        }
    }
}