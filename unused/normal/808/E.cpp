#include <bits/stdc++.h>
using namespace std;

vector<long long> vt[4];

int m;

long long solve()
{
    vector<long long> v1 = vt[2];
    for (int i = 1; i < vt[1].size(); i+=2)
    {
        v1.push_back(vt[1][i] + vt[1][i - 1]);
    }

    sort(v1.begin(), v1.end(), greater<>());
    for (int i = 1; i < v1.size(); i++) v1[i] += v1[i - 1];
    v1.insert(v1.begin(), 0);

    long long ret = 0;

    for (int i = 0; i <= vt[3].size(); i++)
    {
        if (i * 3 > m) break;
        ret = max(ret, (i ? vt[3][i - 1] : 0) + v1[min((int)v1.size() - 1, (m - i * 3) / 2)]);
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        vt[a].push_back(b);
    }

    for (int i = 1; i <= 3; i++)
    {
        sort(vt[i].begin(), vt[i].end(), greater<>());
    }

    for (int i = 1; i < vt[3].size(); i++) vt[3][i] += vt[3][i - 1];

    long long ans = solve();

    if (vt[1].empty() == false)
    {
        int foo = vt[1][0];
        vt[1].erase(vt[1].begin());
        --m;
        ans = max(ans, solve() + foo);
    }

    printf("%lld\n", ans);
}