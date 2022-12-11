#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

long long C(int a, int b)
{
    long long ret = 1;
    for (int i = 0; i < b; i++)
    {
        ret = ret * (a - i) / (i + 1);
    }

    return ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d",&t);
        mp[t]++;
    }

    int total = 0;
    for (auto &e: mp)
    {
        if (total + e.second >= 3)
        {
            printf("%lld\n", C(e.second, 3 - total));
            return 0;
        }

        total += e.second;
    }
}