#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)3e18;

ll solve()
{
    ll x, y, p, q;
    scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
    if (p == q && x < y) return -1;
    if (p == 0 && x > 0) return -1;
    ll l = 0, r = INF / q;
    while(r - l > 1)
    {
        ll d = (l + r) / 2;
        ll qq = q * d, pp = p * d;
        if (y <= qq && x <= pp && pp - x <= qq - y)
            r = d;
        else
            l = d;
    }
    return q * r - y;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--) printf("%lld\n", solve());

    return 0;
}