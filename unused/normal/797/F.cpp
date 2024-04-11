#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;

struct event
{
    int p, t, lv;
    bool operator<(const event &r) const
    {
        return p < r.p;
    }
};

map<int, pair<vector<int>, vector<int>>> levels;
bool yes[30000000];
long long ans;

void solve(vector<int> &v1, vector<int> &v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<vector<int>> dp(v1.size(), vector<int>(v2.size(), -1));

    function<long long(int, int)> D;
    D = [&](int a, int b) -> long long {
        if (a == -1) return 0LL;
        if (a > b) return INF;
        if (dp[a][b] == -1)
        {
            dp[a][b] = min(D(a - 1, b - 1) + abs(v1[a] - v2[b]), D(a, b - 1));
        }
        return dp[a][b];
    };

    ans += D(v1.size() - 1, v2.size() - 1);
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    vector<event> events;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        events.push_back({x, 0, 0});
    }

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        sum += b;
        events.push_back({a, b, 0});
    }

    if (sum < n)
    {
        printf("-1\n");
        return 0;
    }

    sort(events.begin(), events.end());
    int now = 25000000;
    for (auto &e: events)
    {
        if (e.t == 0)
        {
            e.lv = ++now;
            yes[e.lv] = true;
        }
        else
        {
            e.lv = now;
            now -= e.t;
        }
    }

    for (auto &e: events)
    {
        int iter = max(1, e.t);
        for (int i = 0; i < iter; i++, e.lv--)
        {
            if (yes[e.lv] == false) continue;
            (e.t == 0 ? levels[e.lv].first : levels[e.lv].second).push_back(e.p);
        }
    }

    for (auto &e : levels)
    {
        solve(e.second.first, e.second.second);
    }

    printf("%lld\n", ans);
}