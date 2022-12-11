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
#include <cassert>
using namespace std;


int main()
{
    int f, t, t0;
    cin >> f >> t >> t0;
    int a1, t1, p1, a2, t2, p2;
    cin >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;

    long long ans = LLONG_MAX;

    for (int i = 0; i <= (f + a1 - 1) / a1; i++)
    {
        long long cost = p1 * 1ll * i;
        int a_download = min(f, i * a1);
        int rem = f - a_download;
        long long T = t1 * 1ll * a_download;

        if (T > t) continue;

        if (t0 <= t2)
        {
            T += rem * 1ll * t0;
            if (T <= t && ans > cost) ans = cost;
            continue;
        }

        int lo = 0, hi = (rem + a2 - 1) / a2, an = -1;
        while (lo <= hi)
        {
            int mid = (long long)(lo + hi) >> 1;
            int to_download = min(rem, mid * a2);
            if (T + to_download * 1ll * t2 + (rem - to_download) * 1ll * t0 <= t)
            {
                an = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if (an == -1) continue;
        if (ans > cost + an * 1ll * p2)
        {
            ans = cost + an * 1ll * p2;
        }
    }

    swap(a1, a2); swap(t1, t2); swap(p1, p2);

    for (int i = 0; i <= (f + a1 - 1) / a1; i++)
    {
        long long cost = p1 * 1ll * i;
        int a_download = min(f, i * a1);
        int rem = f - a_download;
        long long T = t1 * 1ll * a_download;

        if (T > t) continue;

        if (t0 <= t2)
        {
            T += rem * 1ll * t0;
            if (T <= t && ans > cost) ans = cost;
            continue;
        }

        int lo = 0, hi = (rem + a2 - 1) / a2, an = -1;
        while (lo <= hi)
        {
            int mid = (long long)(lo + hi) >> 1;
            int to_download = min(rem, mid * a2);
            if (T + to_download * 1ll * t2 + (rem - to_download) * 1ll * t0 <= t)
            {
                an = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if (an == -1) continue;
        if (ans > cost + an * 1ll * p2)
        {
            ans = cost + an * 1ll * p2;
        }
    }

    if (ans == LLONG_MAX) ans = -1;
    printf("%lld\n", ans);
}