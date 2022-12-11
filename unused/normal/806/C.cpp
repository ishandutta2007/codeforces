#include <bits/stdc++.h>
using namespace std;

long long dat[100005];
bool fre[100005];
int n;

bool check(int t)
{
    memset(fre, 0, sizeof(fre));
    multiset<long long> lim;
    for (int i = 0; i < t; i++) lim.insert(1);

    for (int i = 0; i < n; i++)
    {
        if (__builtin_popcount(dat[i]) > 1)
        {
            fre[i] = true;
            continue;
        }
        
        auto itr = lim.find(dat[i]);
        if (itr == lim.end()) fre[i] = true;
        else
        {
            lim.insert(dat[i] * 2);
            lim.erase(itr);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (fre[i] == false) continue;
        auto itr = lim.lower_bound(dat[i]);
        if (itr == lim.end()) return false;
        lim.erase(itr);
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&dat[i]);
    }

    int ones = count(dat, dat + n, 1);

    if (check(ones) == false)
    {
        printf("-1\n");
        return 0;
    }

    int lo = 1, hi = ones - 1, ans = ones;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    while (ans <= ones)
    {
        printf("%d ", ans);
        ++ans;
    }
    printf("\n");
}