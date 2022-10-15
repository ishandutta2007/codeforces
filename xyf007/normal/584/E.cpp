#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, a[2001], b[2001], pos[2001];
vector<pair<int, int> > v;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        pos[b[i]] = i;
    }
    long long ans = 0;
    while (1)
    {
        int id = -1;
        for (int i = n; i >= 1; i--)
        {
            if (pos[a[i]] > i)
            {
                id = i;
                break;
            }
        }
        if (id == -1)
        {
            break;
        }
        for (int i = id; i <= pos[a[id]]; i++)
        {
            if (pos[a[i]] <= id)
            {
                ans += i - id;
                v.push_back(make_pair(id, i));
                swap(a[id], a[i]);
                break;
            }
        }
    }
    printf("%lld\n%d\n", ans, (int)v.size());
    for (auto &&i : v)
    {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}