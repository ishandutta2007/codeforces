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

int a[5005];
long long sum[5005];
tuple<long long, int, int> r[5005];

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];

    r[n] = make_tuple(0, n, n);
    long long now = 0;
    int R = n;

    for (int i = n - 1; i >= 0; i--)
    {
        now += a[i];
        if (now < 0)
        {
            now = 0;
            R = i;
        }

        r[i] = max(r[i + 1], make_tuple(now, i, R));
    }

    long long ans = get<0>(r[0]);
    tuple<int, int, int> idx{ 0, get<1>(r[0]), get<2>(r[0]) };
    for (int i = 0; i < n; i++)
    {
        long long res = sum[i] + get<0>(r[i + 1]);
        if (ans < res)
        {
            ans = res;
            idx = make_tuple(i + 1, get<1>(r[i + 1]), get<2>(r[i + 1]));
        }
    }

    printf("%d %d %d\n", get<0>(idx), get<1>(idx), get<2>(idx));
}