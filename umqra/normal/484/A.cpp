#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

ll getLen(ll x)
{
    ll l = 0;
    while (x > 0)
    {
        x /= 2;
        l++;
    }
    return l;
}

ll solve(ll l, ll r)
{
    if (r == 0)
        return 0;
    ll len = getLen(r);
    ll val = 0;
    for (ll pos = len - 1; pos >= 0; pos--)
    {
        ll br = ((r >> pos) & 1LL);
        ll bl = ((l >> pos) & 1LL);
        if (br == bl)
            val |= (br << pos);
        else
        {
            ll x = (1LL << (pos + 1)) - 1;
            if ((r & x) == x)
                return val | x;
            x ^= (1LL << pos);
            return val | x;
        }
    }
    return val;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    return 0;
}