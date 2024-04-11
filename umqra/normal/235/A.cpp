#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;  

#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        puts("1");
        return 0;
    }
    if (n == 2)
    {
        puts("2");
        return 0;
    }

    ll a = n, b = n - 1;
    ll res, ans = -1;
    for (ll a = n; a >= 3; a--)
    {
        b = a - 1;
        for (ll s = a - 2; s >= 1; s--)
        {
            res = a * b / gcd(a, b);
            res = res * s / gcd(res, s);      
            if (res > ans)
                ans = res;
            if (gcd(a, s) == 1 && gcd(b, s) == 1)
                break;
        }
    }
    cout << ans;
    return 0;
}