#include <bits/stdc++.h>
using namespace std;

map<long long, bool> memo;
long long ans = -1;

bool D(long long t, bool print = false)
{
    auto itr = memo.emplace(t, false);
    if (itr.second)
    {
        bool mv = false;
        for (int j = 2; j * 1ll * j <= t; j++)
        {
            if (t % j) continue;
            mv = true;
            if (!D(t / j))
            {
                if (print) ans = t / j;
                itr.first->second = true;
                break;
            }
            if (!D(j))
            {
                if (print) ans = j;
                itr.first->second = true;
                break;
            }
        }

        if (mv == false)
        {
            itr.first->second = true;
            if (print) ans = 0;
        }
    }
    return itr.first->second;
}

int main()
{
    long long q;
    scanf("%lld",&q);
    printf("%d\n", 2 - D(q, true));
    if (ans != -1) printf("%lld\n", ans);
}