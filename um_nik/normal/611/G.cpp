#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll ans;

ll add(ll x, ll y)
{
    return ((x + y) % MOD + MOD) % MOD;
}
ll sub(ll x, ll y)
{
    return add(x, -y);
}
ll mult(ll x, ll y)
{
    return (((x % MOD + MOD) % MOD) * ((y % MOD + MOD) % MOD)) % MOD;
}

struct Point
{
    ll x, y;

    Point() : x(), y() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}

    void scan()
    {
        scanf("%lld%lld", &x, &y);
    }

    Point operator + (const Point &a) const
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    ll operator * (const Point &a) const
    {
        return x * a.y - y * a.x;
    }
    Point operator * (const ll &k) const
    {
        return Point(x * k, y * k);
    }
};

const int N = (int)4e6 + 300;
int n;
Point a[N];
ll totS;
int cntHalf = 0;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--)
        a[i].scan();
    for (int i = 0; i < n; i++)
        a[3 * n + i] = a[2 * n + i] = a[n + i] = a[i];
    totS = 0;
    for (int i = 1; i < n - 1; i++)
        totS += (a[i] - a[0]) * (a[i + 1] - a[0]);

//  printf("Total area = %lld\n", totS);

    ll tmpS = 0;
    int it = 0;
    ll sumVecPr = 0, sumSumVec = 0;
    Point sumP = Point(0, 0), sumSumP = Point(0, 0);
    for (int i = 0; i < n; i++)
    {
        while((tmpS + (a[it] - a[i]) * (a[it + 1] - a[i])) <= totS / 2)
        {
            if ((ll)2 * (tmpS + (a[it] - a[i]) * (a[it + 1] - a[i])) > totS)
                break;
            tmpS += (a[it] - a[i]) * (a[it + 1] - a[i]);

            sumVecPr = add(sumVecPr, a[it] * a[it + 1]);
            sumSumVec = add(sumSumVec, sumVecPr);

            sumP = sumP - a[it] + a[it + 1];
            sumSumP = sumSumP + sumP;
            sumSumP.x %= MOD;
            sumSumP.y %= MOD;
            
            it++;
        }

//      printf("%d %d\n", i, it);

        if ((ll)2 * tmpS == totS)
            cntHalf++;

        ans = add(ans, sumSumVec);
        ans = add(ans, sumSumP * a[i]);

//      printf("%lld\n", ans);

        tmpS -= (a[i + 1] - a[i]) * (a[it] - a[i]);
        
        sumVecPr = sub(sumVecPr, a[i] * a[i + 1]);
        sumSumVec = sub(sumSumVec, ((a[i] * a[i + 1]) % MOD) * (it - i));

        sumP = sumP + a[i] - a[i + 1];
        sumSumP = sumSumP + a[i] * (ll)(it - i) - a[i + 1] * (ll)(it - i);
        sumSumP.x %= MOD;
        sumSumP.y %= MOD;
    }

    if (cntHalf & 1) throw;
    cntHalf /= 2;
    ans = add(ans, 0);
    ll res = sub(mult(totS, ((ll)n * (ll)(n - 3)) / 2), (ll)2 * ans);
    res = add(res, mult(totS, (ll)cntHalf));
    printf("%lld\n", (res % MOD + MOD) % MOD);

    return 0;
}