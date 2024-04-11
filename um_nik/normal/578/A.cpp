#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const double INF = 1e18;

double solve(ll x, ll y)
{
    ll k = x / (2 * y);
    if (k == 0) return INF;
    return (double)x / (double)(2 * k);
}

int main()
{
    ll x, y;
    cin >> x >> y;
    if (x < y)
    {
        printf("-1\n");
        return 0;
    }
    if (x == y)
    {
        printf("%d\n", x);
        return 0;
    }
    printf("%.12lf\n", min(solve(x - y, y), solve(x + y, y)));

    return 0;
}