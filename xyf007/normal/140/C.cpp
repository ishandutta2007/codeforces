#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
#include <unordered_map>
int n;
std::unordered_map<int, int> mp;
std::vector<std::tuple<int, int, int>> v;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;
        mp[x]++;
    }
    std::priority_queue<std::pair<int, int>> q;
    for (auto &&i : mp)
    {
        q.emplace(i.second, i.first);
    }
    int ans = 0;
    while (q.size() >= 3)
    {
        ans++;
        std::pair<int, int> t1 = q.top(), t2, t3;
        q.pop();
        t2 = q.top();
        q.pop();
        t3 = q.top();
        q.pop();
        if (t1.second < t2.second)
        {
            std::swap(t1, t2);
        }
        if (t1.second < t3.second)
        {
            std::swap(t1, t3);
        }
        if (t2.second < t3.second)
        {
            std::swap(t2, t3);
        }
        v.emplace_back(t1.second, t2.second, t3.second);
        if (--t1.first)
        {
            q.emplace(t1);
        }
        if (--t2.first)
        {
            q.emplace(t2);
        }
        if (--t3.first)
        {
            q.emplace(t3);
        }
    }
    std::cout << ans << '\n';
    for (auto &&i : v)
    {
        std::cout << std::get<0>(i) << ' ' << std::get<1>(i) << ' ' << std::get<2>(i) << '\n';
    }
    return 0;
}