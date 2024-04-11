#include <bits/stdc++.h>
using namespace std;

long long ans[2001];

struct edge
{
    int s, e, v;
    bool operator<(const edge &r) const
    {
        return v < r.v;
    }
};

vector<edge> vt;

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int t;
            scanf("%d",&t);
            vt.push_back({i, j, t});
        }
    }

    for (int i = 1; i <= n; i++) ans[i] = -1;

    sort(vt.begin(), vt.end());

    int mindist = vt[0].v;
    long long base = mindist * (long long)(n - 1);

    for (int i = 0, j; i < vt.size(); i = j)
    {
        for (j = i + 1; j < vt.size() && vt[i].v == vt[j].v; ++j)
            ;

        int v = vt[i].v - mindist;

        if (v == 0)
        {
            for (int k = i; k < j; k++) ans[vt[k].s] = ans[vt[k].e] = 0;
            continue;
        }

        for (bool flag = true; flag;)
        {
            flag = false;

            for (int k = i; k < j; k++)
            {
                if (ans[vt[k].s] == -1 && ans[vt[k].e] == -1)
                {
                    ans[vt[k].s] = ans[vt[k].e] = v * 2;
                    flag = true;
                }
                else if (ans[vt[k].s] == -1)
                {
                    ans[vt[k].s] = ans[vt[k].e] + v;
                    flag = true;
                }
                else if (ans[vt[k].e] == -1)
                {
                    ans[vt[k].e] = ans[vt[k].s] + v;
                    flag = true;
                }
                else
                {
                    if (ans[vt[k].s] > v * 2 || ans[vt[k].e] > v * 2 || abs(ans[vt[k].s] - ans[vt[k].e]) > v)
                    {
                        ans[vt[k].s] = min({ans[vt[k].s], ans[vt[k].e] + v, v * 2LL});
                        ans[vt[k].e] = min({ans[vt[k].e], ans[vt[k].s] + v, v * 2LL});
                        flag = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i] + base);

    fflush(stdout);
    _Exit(0);
}