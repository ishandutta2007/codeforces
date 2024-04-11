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

int a[1005], b[1005], c[1005], d[1005], e[1005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j) {
            a[j] -= a[i];
            b[j] -= b[i];
            c[j] -= c[i];
            d[j] -= d[i];
            e[j] -= e[i];
            }
        }

        bool wrong = false;

        for (int j = 1; j <= n; j++)
        {
            if (j == i) continue;
            for (int k = j + 1; k <= n; k++)
            {
                if (k == i) continue;
                if (
                    a[j]*a[k]+
                    b[j]*b[k]+
                    c[j]*c[k]+
                    d[j]*d[k]+
                    e[j]*e[k] > 0)
                {
                    wrong = true;
                    goto fal;
                }
            }
        }

fal:

        if (wrong == false) ans.push_back(i);

        for (int j = 1; j <= n; j++)
        {
            if (i != j) {
            a[j] += a[i];
            b[j] += b[i];
            c[j] += c[i];
            d[j] += d[i];
            e[j] += e[i];
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (int t : ans) printf("%d\n", t);
}