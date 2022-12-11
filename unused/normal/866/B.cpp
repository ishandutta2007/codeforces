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

int s[100005], a[100005], b[100005];

long long calc(vector<pair<int, int>> L, vector<pair<int, int>> R, long long mid, int SS)
{
    int S = SS;
    //  L 
    long long ret = 0;

    while (L.empty() == false)
    {
        ret += L.back().first * 1ll * L.back().second;
        S -= L.back().second;
        L.pop_back();
    }

    S -= min(mid, (long long)S);

    long long rsum = 0;
    for (auto &e : R) rsum += e.second;

    //  : S
    //  : rsum - S
    //  : (rsum - S + SS - 1) / SS * SS

    long long buy = (rsum - S + SS - 1) / SS * SS;

    while (R.empty() == false && buy)
    {
        long long eat = min(R.back().second + 0LL, buy);
        ret += R.back().first * 1ll * eat;
        R.back().second -= eat;
        buy -= eat;

        if (R.back().second == 0) R.pop_back();
    }

    return ret;
}

int main()
{
    int n, S;
    scanf("%d%d",&n,&S);

    long long ans = 0;

    vector<pair<int, int>> L, R;
    long long lsum = 0, rsum = 0, mid = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d",&s[i],&a[i],&b[i]);
        int mv = min(a[i], b[i]);
        ans += s[i] * 1ll * min(a[i], b[i]);
        a[i] -= mv; b[i] -= mv;

        if (a[i] > 0)
        {
            L.emplace_back(a[i], s[i]);
            lsum += s[i];
        }
        else if (b[i] > 0)
        {
            R.emplace_back(b[i], s[i]);
            rsum += s[i];
        }
        else mid += s[i];
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    long long lp = lsum / S * S;
    while (lp)
    {
        long long eat = min(lp, 0LL + L.back().second);
        L.back().second -= eat;
        lp -= eat;
        ans += eat * L.back().first;

        if (L.back().second == 0) L.pop_back();
    }
    
    long long rp = rsum / S * S;
    while (rp)
    {
        long long eat = min(rp, 0LL + R.back().second);
        R.back().second -= eat;
        rp -= eat;
        ans += eat * R.back().first;

        if (R.back().second == 0) R.pop_back();
    }

    printf("%lld\n", ans + max(calc(L, R, mid, S), calc(R, L, mid, S)));
}