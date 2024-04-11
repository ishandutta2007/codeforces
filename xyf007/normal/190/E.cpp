#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
int n, m, c[500001], pre[500001], nxt[500001], st;
std::set<std::pair<int, int>> e;
std::vector<int> ans[500001];
void Bfs(int s)
{
    std::queue<int> q;
    q.emplace(s);
    c[s] = s;
    st = nxt[s];
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = st; i <= n; i = nxt[i])
        {
            if (!c[i] && !e.count({std::min(i, u), std::max(i, u)}))
            {
                c[i] = s;
                nxt[pre[i]] = nxt[i];
                pre[nxt[i]] = pre[i];
                if (i == st)
                {
                    st = nxt[i];
                }
                q.emplace(i);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        if (u > v)
        {
            std::swap(u, v);
        }
        e.emplace(u, v);
    }
    st = 1;
    std::iota(nxt + 1, nxt + n + 1, 2);
    std::iota(pre + 1, pre + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
        {
            Bfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[c[i]].emplace_back(i);
    }
    std::cout << std::count_if(ans + 1, ans + n + 1, [](const std::vector<int> &x) -> bool { return x.size() > 0; }) << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (ans[i].size())
        {
            std::cout << ans[i].size() << ' ';
            for (auto &&j : ans[i])
            {
                std::cout << j << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}