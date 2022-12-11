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
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int dat[500005];
bool seg[1048576];

void setseg(int t)
{
    t += 524288;
    while (t >= 1)
    {
        seg[t] = true;
        t >>= 1;
    }
}

bool query(int a, int b)
{
    a += 524288; b += 524288;
    while (a <= b)
    {
        if (a & 1)
        {
            if (seg[a]) return true;
            a++;
        }
        if (!(b & 1))
        {
            if (seg[b]) return true;
            b--;
        }
        a >>= 1; b >>= 1;
    }
    return false;
}

int main()
{
    int n, k, d;
    scanf("%d%d%d",&n,&k,&d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&dat[i]);
    }

    sort(dat, dat + n);
    setseg(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int LOW = i + k;
        int HIGH = upper_bound(dat, dat + n, dat[i] + d) - dat;

        if (query(LOW, HIGH)) setseg(i);
    }

    printf(seg[524288] ? "YES" : "NO");
}