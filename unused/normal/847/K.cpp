#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
map<pair<int, int>, int> price;

int get_idx(const char *str)
{
    return mp.emplace(str, mp.size()).first->second;
}

int main()
{
    int n, a, b, k, f;
    scanf("%d%d%d%d%d",&n,&a,&b,&k,&f);

    int last = -1;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        char A[33], B[33];
        scanf("%s%s", A, B);

        int x = get_idx(A), y = get_idx(B);
        if (last == x)
        {
            price[minmax(x, y)] += b;
            total += b;
        }
        else
        {
            price[minmax(x, y)] += a;
            total += a;
        }

        last = y;
    }

    vector<int> vt;
    for (auto &e : price) vt.push_back(e.second);
    sort(vt.begin(), vt.end());

    while (vt.empty() == false && k--)
    {
        if (vt.back() <= f) break;
        total += f - vt.back();
        vt.pop_back();
    }
    printf("%d\n", total);
}