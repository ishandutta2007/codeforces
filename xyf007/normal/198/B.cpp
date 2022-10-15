#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
struct Node
{
    int pos, h, t;
    Node(int pos = 0, int h = 0, int t = 0) : pos(pos), h(h), t(t) {}
};
int n, k;
char s1[100001], s2[100001];
bool vis[200001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k >> (s1 + 1) >> (s2 + 1);
    std::queue<Node> q;
    q.emplace(1, 1, 0);
    vis[1] = true;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if (tmp.h <= tmp.t)
        {
            continue;
        }
        int l = tmp.pos > n ? 2 : 1, p = tmp.pos > n ? tmp.pos - n : tmp.pos;
        if (p + k > n)
        {
            std::cout << "YES";
            return 0;
        }
        if (l == 1)
        {
            if (s1[p + 1] != 'X' && !vis[p + 1])
            {
                q.emplace(p + 1, tmp.h + 1, tmp.t + 1);
                vis[p + 1] = true;
            }
            if (p - 1 && s1[p - 1] != 'X' && !vis[p - 1])
            {
                q.emplace(p - 1, tmp.h - 1, tmp.t + 1);
                vis[p - 1] = true;
            }
            if (s2[p + k] != 'X' && !vis[p + k + n])
            {
                q.emplace(p + k + n, tmp.h + k, tmp.t + 1);
                vis[p + k + n] = true;
            }
        }
        else
        {
            if (s2[p + 1] != 'X' && !vis[p + 1 + n])
            {
                q.emplace(p + 1 + n, tmp.h + 1, tmp.t + 1);
                vis[p + 1 + n] = true;
            }
            if (p - 1 && s2[p - 1] != 'X' && !vis[p - 1 + n])
            {
                q.emplace(p - 1 + n, tmp.h - 1, tmp.t + 1);
                vis[p - 1 + n] = true;
            }
            if (s1[p + k] != 'X' && !vis[p + k])
            {
                q.emplace(p + k, tmp.h + k, tmp.t + 1);
                vis[p + k] = true;
            }
        }
    }
    std::cout << "NO";
    return 0;
}