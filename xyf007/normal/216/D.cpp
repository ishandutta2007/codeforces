#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
int n;
std::vector<int> a[1001];
class FenwickTree
{
private:
    int t_[100001];

public:
    FenwickTree() {}
    void Add(int, int);
    int Query(int);
    ~FenwickTree() {}
} T1, T2;

void FenwickTree::Add(int x, int v)
{
    while (x <= 100000)
    {
        t_[x] += v;
        x += x & -x;
    }
}

int FenwickTree::Query(int x)
{
    int s = 0;
    while (x)
    {
        s += t_[x];
        x -= x & -x;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    size_t k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        a[i].resize(k);
        for (size_t j = 0; j < k; j++)
        {
            std::cin >> a[i].at(j);
        }
        std::sort(a[i].begin(), a[i].end());
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto &&j : a[(i + 1) % n])
        {
            T1.Add(j, 1);
        }
        for (auto &&j : a[(i + n - 1) % n])
        {
            T2.Add(j, 1);
        }
        for (size_t j = 0; j < a[i].size() - 1; j++)
        {
            ans += T1.Query(a[i].at(j + 1)) - T1.Query(a[i].at(j)) != T2.Query(a[i].at(j + 1)) - T2.Query(a[i].at(j));
        }
        for (auto &&j : a[(i + 1) % n])
        {
            T1.Add(j, -1);
        }
        for (auto &&j : a[(i + n - 1) % n])
        {
            T2.Add(j, -1);
        }
    }
    std::cout << ans;
    return 0;
}