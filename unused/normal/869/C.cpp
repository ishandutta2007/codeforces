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

constexpr int MOD = 998244353;

int dp[5005][5005];

int D(int a, int b)
{
    if (a == 0 || b == 0) return 1;

    if (dp[a][b] == 0)
    {
        dp[a][b] = (b * 1ll * D(a - 1, b - 1) + D(a - 1, b)) % MOD;
    }

    return dp[a][b];
}

int main()
{
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);

    if (a>b) swap(a,b);
    if (b>c) swap(b,c);
    if (a>b) swap(a,b);

    printf("%lld\n", D(a, b) * 1ll * D(b, c) % MOD * D(a, c) % MOD);
}