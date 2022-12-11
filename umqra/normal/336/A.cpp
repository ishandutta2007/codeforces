#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
               
    ll x, y;
    cin >> x >> y;
    ll sgnX = 1, sgnY = 1;
    if (x < 0)
    {
        sgnX = -1;
        x = -x;
    }
    if (y < 0)
    {
        sgnY = -1;
        y = -y;
    }

    ll l = 0, r = (ll)2e9;
    while (r - l > 1)
    {
        ll m = (l + r) / 2;     
        if (m * (y - m) + m * x <= 0)
            r = m;
        else
            l = m;
    }

    if (0 < sgnX * r)
        cout << 0 << ' ' << sgnY * r << " " << sgnX * r << " " << 0;
    else
        cout << sgnX * r << " " << 0 << ' ' << 0 << ' ' << sgnY * r;
    return 0;
}