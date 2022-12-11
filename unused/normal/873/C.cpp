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

int mat[111][111];

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        int b1 = 0, b2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[j][i] == 0) continue;

            int sum2 = 0;
            for (int l = j; l < j + k && l < n; l++)
            {
                sum2 += mat[l][i];
            }

            if (make_pair(b1, -b2) < make_pair(sum2, -sum))
            {
                b1 = sum2;
                b2 = sum;
            }

            sum += mat[j][i];
        }

        ans1 += b1;
        ans2 += b2;
    }

    printf("%d %d\n", ans1, ans2);
}