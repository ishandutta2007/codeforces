#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
int dp[N][2];
vector<pii> g[N];
int n, k;

void dfs(int v, int par)
{
    vector<pii> a;
    for (pii e : g[v])
    {
        int u = e.first;
        if (u == par) continue;
        dfs(u, v);
        a.push_back(mp(dp[u][0] + e.second, dp[u][1] + e.second));
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < k - 1 && i < (int)a.size(); i++)
        sum += a[i].first;

    dp[v][0] = sum;
    
    if ((int)a.size() <= k - 1)
    {
        for (pii t : a)
            dp[v][1] = max(dp[v][1], sum + t.second - t.first);
        return;
    }

    for (int i = k; i < (int)a.size(); i++)
        dp[v][1] = max(dp[v][1], sum + a[i].second);
    sum += a[k - 1].first;
    for (int i = 0; i < k; i++)
        dp[v][1] = max(dp[v][1], sum + a[i].second - a[i].first);

    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        g[v].push_back(mp(u, w));
        g[u].push_back(mp(v, w));
    }
    dfs(0, -1);
    printf("%d\n", max(dp[0][0], dp[0][1]));

    return 0;
}