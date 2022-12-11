#include <bits/stdc++.h>
using namespace std;

using res = array<int, 9>;

vector<int> graph[707];
char str[707];
int match[707];
int len;
res dp[707];

constexpr int MOD = 1000000007;

res merge(const res &left, const res &right)
{
    res ret = {};
    for (int i = 0; i < 9; i++)
    {
        int ll = i / 3, lr = i % 3;
        for (int j = 0; j < 9; j++)
        {
            int rl = j / 3, rr = j % 3;
            if (lr && lr == rl) continue;

            ret[ll * 3 + rr] = (ret[ll * 3 + rr] + left[i] * 1ll * right[j]) % MOD;
        }
    }

    return ret;
}

void dfs(int t)
{
    for (int nxt : graph[t])
    {
        dfs(nxt);
    }

    if (graph[t].empty())
    {
        dp[t][1] = dp[t][2] = dp[t][3] = dp[t][6] = 1;
        return;
    }

    res child = dp[graph[t][0]];
    for (int i = 1; i < graph[t].size(); i++)
    {
        child = merge(child, dp[graph[t][i]]);
    }

    for (int i = 0; i < 9; i++)
    {
        int l = i / 3, r = i % 3;
        if (t && l == 0 && r == 0) continue;
        if (l && r) continue;

        for (int j = 0; j < 9; j++)
        {
            int cl = j / 3, cr = j % 3;
            if (l && l == cl) continue;
            if (r && r == cr) continue;

            dp[t][i] = (dp[t][i] + child[j]) % MOD;
        }
    }
}

int main()
{
    scanf("%s", str + 1);
    stack<int> stk;
    stk.push(0);
    for (len = 1; str[len]; len++)
    {
        if (str[len] == '(') stk.push(len);
        else
        {
            int t = stk.top(); stk.pop();
            graph[stk.top()].push_back(t);
        }
    }

    dfs(0);

    printf("%d\n", dp[0][0]);
}