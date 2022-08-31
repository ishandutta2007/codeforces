#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 1005;

int n, m;
vector<int> go[N];
bool used[N];

void dfs(int v)
{
    used[v] = true;
    for (int to : go[v])
        if (!used[to])
            dfs(to);
}

void fail()
{
    puts("no");
    exit(0);
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

    if (m != n - 1)
        fail();

    dfs(0);
    for (int i = 0; i < n; i++)
        if (!used[i])
            fail();

    puts("yes");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}