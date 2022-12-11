#include <bits/stdc++.h>
using namespace std;

int dat[100005];
int ans[100005];

int dp[100005];
int K;
int n;
constexpr int sqrn = 300;

int D(int t)
{
    if (t > n) return 0;

    if (dp[t] == 0 || K > sqrn)
    {
        dp[t] = 1 + D(t + dat[t] + K);
    }

    return dp[t];
}

struct query
{
    int p, k, idx;
    bool operator<(const query &q) const
    {
        return k < q.k;
    }
};

query qry[100005];

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&dat[i]);

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        qry[i] = {a, b, i};
    }

    sort(qry, qry + q);

    for (int i = 0; i < q; i++)
    {
        if (qry[i].k != K)
        {
            if (qry[i].k <= sqrn) memset(dp, 0, sizeof(dp));
            K = qry[i].k;
        }

        ans[qry[i].idx] = D(qry[i].p);
    }

    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}