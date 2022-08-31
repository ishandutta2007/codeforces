#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> ans;

ll gcd(ll x, ll y)
{
    while(true)
    {
        if (x == y)
            return x;
        if (x < y)
        {
            ll p = (y - 1) / x;
            ans.push_back(-p);
            y -= x * p;
        }
        else
        {
            ll p = (x - 1) / y;
            ans.push_back(p);
            x -= y * p;
        }
    }
    throw;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    if (gcd(x, y) != 1)
    {
        printf("Impossible\n");
        return 0;
    }
//  reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%lld%c", abs(ans[i]), (ans[i] > 0 ? 'A' : 'B'));
    printf("\n");

    return 0;
}