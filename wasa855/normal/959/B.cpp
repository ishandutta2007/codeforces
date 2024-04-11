#include <bits/stdc++.h>

using ll = long long;

ll Pri[100050], Num[100050];

ll Read()
{
    ll n = 0;
    char ch = std::getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = std::getchar();
    }

    while (ch <= '9' && ch >= '0')
    {
        n = n * 10 + ch - '0';
        ch = std::getchar();
    }

    return n;
}

int main()
{
    ll n, k, m;
    std::cin >> n >> k >> m;
    std::unordered_map<std::string, ll> Map;
    std::string Str;
    for (ll i = 1; i <= n; ++i)
    {
        std::cin >> Str;
        Map[Str] = i;
    }

    for (ll i = 1; i <= n; ++i)
    {
        Pri[i] = Read();
    }

    for (ll i = 1; i <= k; ++i)
    {
        ll p, Min = 999999999 + 50;
        p = Read();
        for (ll i = 1; i <= p; ++i)
        {
            Num[i] = Read();
            if (Pri[Num[i]] < Min)
            {
                Min = Pri[Num[i]];
            }
        }

        for (ll i = 1; i <= p; ++i)
        {
            Pri[Num[i]] = Min;
        }
    }

    ll Sum = 0;
    for (ll i = 1; i <= m; ++i)
    {
        std::cin >> Str;
        Sum += Pri[Map[Str]];
    }

    std::cout << Sum << std::endl;

    return 0;
}