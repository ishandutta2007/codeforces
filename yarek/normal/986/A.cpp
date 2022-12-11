#include <bits/stdc++.h>
using namespace std;

const int N = 100001, K = 101, inf = 1e9;
int dst[N][K];
vector<int> g[N];

int main()
{
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            dst[i][j] = inf;
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        dst[i][a] = 0;
        q.push({ i, a });
    }
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(!q.empty())
    {
        int v = q.front().first, c = q.front().second;
        int d = dst[v][c] + 1;
        q.pop();
        for(auto u: g[v])
            if(dst[u][c] == inf)
            {
                dst[u][c] = d;
                q.push({ u, c });
            }
    }
    for(int i = 1; i <= n; i++)
    {
        sort(dst[i] + 1, dst[i] + k + 1);
        long long ans = 0;
        for(int j = 1; j <= s; j++)
            ans += dst[i][j];
        printf("%lld ", ans);
    }
    puts("");
}