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

constexpr int MOD = 1000000007;

vector<int> graph[100005];
int m, k, x;

// dp[][0][x] :  k     x
// dp[][1][x] :  k    x( )
// dp[][2][x] :  k     x
int dp[100005][3][11];

void dfs(int t, int p)
{
    vector<int> childs;

    for (int nxt : graph[t])
    {
        if (nxt == p) continue;
        childs.push_back(nxt);
        dfs(nxt, t);
    }


    if (childs.empty())
    {
        dp[t][0][0] = k - 1;
        dp[t][1][1] = 1;
        dp[t][2][0] = m - k;
        return;
    }

    int ch = childs.back();

    for (int i = 0; i <= x; i++)
    {
        dp[t][0][i] = 1ll * (k - 1) * (dp[ch][0][i] + 0ll + dp[ch][1][i] + dp[ch][2][i]) % MOD;
        dp[t][1][i] = i ? dp[ch][0][i - 1] : 0;
        dp[t][2][i] = 1ll * (m - k) * (dp[ch][0][i] + dp[ch][2][i]) % MOD;
    }

    childs.pop_back();

    for (int ch : childs)
    {
        int ndp[3][11] = {};
        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                ndp[0][i] = (ndp[0][i] + 1ll * dp[t][0][j] * (dp[ch][0][i - j] + 0ll + dp[ch][1][i - j] + dp[ch][2][i - j])) % MOD;
                ndp[1][i] = (ndp[1][i] + 1ll * dp[t][1][j] * dp[ch][0][i - j]) % MOD;
                ndp[2][i] = (ndp[2][i] + 1ll * dp[t][2][j] * (dp[ch][0][i - j] + dp[ch][2][i - j])) % MOD;
            }
        }

        memcpy(dp[t], ndp, sizeof(ndp));
    }
}

int main()
{
    int n;
    scanf("%d%d",&n,&m);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    scanf("%d%d",&k,&x);

    dfs(1, -1);

    long long ans = 0;
    for (int i = 0; i <= x; i++)
    {
        ans += 0ll + dp[1][0][i] + dp[1][1][i] + dp[1][2][i];
    }

    printf("%lld\n", ans % MOD);
}