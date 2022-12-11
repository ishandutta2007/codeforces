#include <bits/stdc++.h>
using namespace std;

set<long long> lucky;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 12; i++)
    {
        long long base = 1;
        for (int j = 0; j < i; j++) base *= 10;
        for (int j = 0; j <= 9; j++)
        {
            lucky.insert(base * j);
        }
    }

    printf("%lld\n", *lucky.upper_bound(n) - n);
}