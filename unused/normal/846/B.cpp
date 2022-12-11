#include <cctype>
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

int t[55];

int main()
{
    int n, k, m;
    scanf("%d%d%d",&n,&k,&m);
    for (int i = 1; i <= k; i++) scanf("%d",&t[i]);

    sort(t + 1, t + k + 1);

    int ans = 0;
    int total = accumulate(t+1, t+1+k, 0);

    for (int all = 0; all <= n; all++)
    {
        long long rem = m - all * 1ll * total;
        if (rem < 0) continue;

        int score = (k + 1) * all;

        for (int j = 1; j <= k; j++)
        {
            for (int x = all; x < n; x++)
            {
                if (rem < t[j]) break;
                rem -= t[j];
                ++score;
            }
        }

        ans = max(ans, score);
    }

    printf("%d\n", ans);
}