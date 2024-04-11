#pragma GCC target("arch=haswell")
#include <bits/stdc++.h>
using namespace std;

pair<int, int> divs[500005];
int cnt[500005];
int dat[200005];
bool on[200005];
int total;
long long ans;

void add(int t)
{
    ans += total;
    ++total;

    vector<int> primes;
    for (int i = t; i > 1; i = divs[i].second)
        primes.push_back(divs[i].first);

    for (int i = 1; i < (1 << primes.size()); i++)
    {
        int x = 1;
        for (int j = 0; j < primes.size(); j++)
        {
            if (i & (1 << j))
            {
                x *= primes[j];
            }
        }

        if (__builtin_popcount(i) & 1)
            ans -= cnt[x];
        else
            ans += cnt[x];

        ++cnt[x];
    }
}

void sub(int t)
{
    --total;
    ans -= total;

    vector<int> primes;
    for (int i = t; i > 1; i = divs[i].second)
        primes.push_back(divs[i].first);

    for (int i = 1; i < (1 << primes.size()); i++)
    {
        int x = 1;
        for (int j = 0; j < primes.size(); j++)
        {
            if (i & (1 << j))
            {
                x *= primes[j];
            }
        }

        --cnt[x];

        if (__builtin_popcount(i) & 1)
            ans += cnt[x];
        else
            ans -= cnt[x];
    }
}

void f(int idx)
{
    if (on[idx]) sub(dat[idx]);
    else add(dat[idx]);
    on[idx] = !on[idx];
}

int main()
{
    divs[1] = {1, 1};

    for (int i = 2; i <= 500000; i++)
    {
        if (divs[i].first) continue;

        divs[i].first = i;
        divs[i].second = 1;

        for (int j = i * 2; j <= 500000; j += i)
        {
            divs[j].first = i;
            divs[j].second = j / i;
            while (divs[j].second % i == 0)
                divs[j].second /= i;
        }
    }

    int n, q;
    scanf("%d%d",&n,&q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&dat[i]);
    }

    while (q--)
    {
        int x;
        scanf("%d",&x);
        f(x - 1);
        printf("%lld\n", ans);
    }
}