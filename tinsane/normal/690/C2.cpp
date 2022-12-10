#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 100500;

int n, m;
vector<int> go[N];
int dist[N];

void dfs(int v, int p, int d)
{
    dist[v] = d;
    for (int to : go[v])
    {
        if (to == p)
            continue;
        dfs(to, v, d + 1);
    }
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        go[a].push_back(b);
        go[b].push_back(a);
    }

    dfs(0, -1, 0);
    int a = max_element(dist, dist + n) - dist;
    dfs(a, -1, 0);
    int b = max_element(dist, dist + n) - dist;

    printf("%d\n", dist[b]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}