#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;

struct Item
{
    ll x, y;
    int id;

    Item() : x(), y(), id() {}

    void scan(int _id)
    {
        id = _id;
        ll x1, y1;
        scanf("%lld%lld%lld%lld", &x, &y, &x1, &y1);
        x += x1;
        y += y1;
    }
};

bool cmp1(const Item &I1, const Item &I2)
{
    return I1.x < I2.x;
}
bool cmp2(const Item &I1, const Item &I2)
{
    return I1.x > I2.x;
}
bool cmp3(const Item &I1, const Item &I2)
{
    return I1.y < I2.y;
}
bool cmp4(const Item &I1, const Item &I2)
{
    return I1.y > I2.y;
}

const int N = 100100;

Item a[N], b[N], c[N], d[N];
set<int> used;
int n, k;

ll ans = (ll)1e18 + 10;

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    freopen ("err.txt", "w", stderr);
#endif

    scanf("%d%d", &n, &k);
    if (k >= n) throw;
    for (int i = 0; i < n; i++)
        a[i].scan(i);
    for (int i = 0; i < n; i++)
        b[i] = c[i] = d[i] = a[i];
    sort(a, a + n, cmp1);
    sort(b, b + n, cmp2);
    sort(c, c + n, cmp3);
    sort(d, d + n, cmp4);
    for (int A = 0; A <= k; A++)
        for (int B = 0; B <= k; B++)
            for (int C = 0; C <= k; C++)
                for (int D = 0; D <= k; D++)
                {
                    used.clear();
                    for (int i = 0; i < A; i++)
                        used.insert(a[i].id);
                    for (int i = 0; i < B; i++)
                        used.insert(b[i].id);
                    for (int i = 0; i < C; i++)
                        used.insert(c[i].id);
                    for (int i = 0; i < D; i++)
                        used.insert(d[i].id);
                    if ((int)used.size() > k) continue;
                    ll x = b[B].x - a[A].x;
                    ll y = d[D].y - c[C].y;
                    if (x < 0 || y < 0) throw;
                    x = (x + 1LL) / 2LL;
                    y = (y + 1LL) / 2LL;
                    x = max(x, 1LL);
                    y = max(y, 1LL);
                    ll S = x * y;
                    ans = min(ans, S);
                }
    printf("%lld\n", ans);

    return 0;
}