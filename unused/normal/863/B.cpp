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

int w[555];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n * 2; i++) scanf("%d", &w[i]);

    int ans = 2e9;

    sort(w, w + n * 2);

    for (int i = 0; i < n * 2; i++)
    {
        for (int j = i + 1; j < n * 2; j++)
        {
            int t = 0;
            for (int k = 0, c = 0; k < n * 2; k++)
            {
                if (k == i || k == j) continue;
                if (c == 0)
                {
                    c = w[k];
                }
                else
                {
                    t += abs(c - w[k]);
                    c = 0;
                }
            }

            ans = min(ans, t);
        }
    }
    printf("%d\n", ans);
}