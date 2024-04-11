#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;
const int N = 200500;
const ll UNDEF = (ll)1e18;

int n;
ll k;
ll a[N];
ll pref[N];

void solve()
{
    scanf("%d%lld", &n, &k);
    n++;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            pref[i] = a[0];
        else
            pref[i] = pref[i - 1] + a[i];
        if (abs(pref[i]) % 2 == 1)
        {
            for (int j = i; j < n; j++)
                pref[j] = UNDEF;
            break;
        }
        pref[i] /= 2;
    }

    ll sum = 0;
    int cnt = 0;

    for (int i = n - 1; i >= 0 && abs(sum) < k; i--)
    {
        if (i == 0 || pref[i - 1] != UNDEF)
        {
            ll pr = (i == 0 ? 0 : pref[i - 1]);
            ll val = -2 * sum - pr;
            if (abs(val) <= k && (i < n - 1 || val != 0))
                cnt++;
        }
        sum = 2 * sum + a[i];
    }

    printf("%d\n", cnt);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}