#pragma GCC target("arch=ivybridge")
#include <bits/stdc++.h>
using namespace std;

string str;

int dp[1001];
int dp2[1001][1001];
int comb[1001][1001];

constexpr int MOD = 1000000007;

int D(int x)
{
    if (x == 1) return 0;
    if (dp[x] == 0) dp[x] = D(__builtin_popcount(x)) + 1;
    return dp[x];
}

int C(int a, int b)
{
    if (a < b || b < 0) return 0;
    if (a == b || b == 0) return 1;
    if (comb[a][b] == 0)
    {
        comb[a][b] = C(a - 1, b - 1) + C(a - 1, b);
        if (comb[a][b] >= MOD) comb[a][b] -= MOD;
    }
    return comb[a][b];
}

int E(int idx, int need)
{
    if (need == 0) return 1;
    if (str.size() - idx < need) return 0;

    if (dp2[idx][need] == -1)
    {
        if (str[idx] == '0') dp2[idx][need] = E(idx + 1, need);
        else
        {
            dp2[idx][need] = C(str.size() - idx - 1, need) + E(idx + 1, need - 1);
            if (dp2[idx][need] >= MOD) dp2[idx][need] -= MOD;
        }
    }
    return dp2[idx][need];
}

int main()
{
    memset(dp2, -1, sizeof(dp2));
    cin.sync_with_stdio(false);
    cin >> str;
    int k;
    cin >> k;

    if (k == 0)
    {
        printf("1\n");
        return 0;
    }

    int ans = 0;

    for (int i = 1; i <= 1000; i++)
    {
        if (D(i) == k - 1)
        {
            ans += E(0, i);
            if (ans >= MOD) ans -= MOD;
        }
    }

    if (k == 1)
    {
        ans--;
        if (ans < 0) ans += MOD;
    }

    printf("%d\n", ans);
}