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

long long dp2[66][11][2];
int lim[66];
int len, b;

long long D2(int rem, int on, bool lead)
{
    if (on > b) return 0;
    if (on < 0) return 0;
    if (rem == 0) return on == 0;

    auto &ret = dp2[rem][on][lead];

    if (ret == -1)
    {
        if (lead) ret = D2(rem - 1, 1, false) * (b - 1);
        else ret = on * D2(rem - 1, on - 1, false) + (b - on) * D2(rem - 1, on + 1, false);
    }

    return ret;
}

long long D(int rem, int flag, bool full, bool lead)
{
    if (rem == 0) return !flag;
    if (full == false)
    {
        return D2(rem, __builtin_popcount(flag), lead);
    }
    else
    {
        long long ret = 0;
        for (int i = lead; i <= lim[len - rem]; i++)
        {
            ret += D(rem - 1, flag ^ (1 << i), i == lim[len - rem], false);
        }
        return ret;
    }
}

long long solve(int b, long long f)
{
    ::b = b;
    len = 0;
    do
    {
        lim[len++] = f % b;
        f /= b;
    } while (f);
    reverse(lim, lim + len);

    memset(dp2, -1, sizeof(dp2));

    long long ret = 0;
    for (int i = 2; i <= len; i += 2)
    {
        ret += D(i, 0, i == len, true);
    }

    return ret;
}

int main()
{
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int b; long long l, r;
        scanf("%d%lld%lld",&b,&l,&r);

        printf("%lld\n", solve(b, r) - solve(b, l - 1));
    }
}