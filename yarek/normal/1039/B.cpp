#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

bool query(ll a, ll b)
{
    assert(a <= b && 1 <= a && b <= n);
    printf("%lld %lld\n", a, b);
    fflush(stdout);
    char ans[5];
    scanf("%s", ans);
    if(ans[0] == 'N')
        return false;
    if(ans[0] == 'Y' && a != b)
        return true;
    exit(0);
}

ll random(ll a, ll b)
{
    static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    return rnd() % (b - a + 1) + a;
}

int main()
{
    
    int k;
    scanf("%lld %d", &n, &k);
    ll a = 1, b = n;
    while(true)
    {
        ll l, r;
        if(b - a <= 4 * k)
            l = r = random(a, b);
        else
        {
            l = a;
            r = (a + b) / 2;
        }
        if(query(l, r))
        {
            a = max(1LL, l - k);
            b = min(n, r + k);
        }
        else if(l == a)
        {
            a = max(1LL, r + 1 - k);
            b = min(n, b + k);
        }
        else
        {
            a = max(1LL, a - k);
            b = min(n, b + k);
        }
    }
}