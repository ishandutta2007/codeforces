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

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

const int LOG = 30;
const ll C = 1 << LOG;

const int N = 200;

ll a[N][2];
int aSz;
ll b[N][2];
int bSz;

void goA(ll L, ll R, ll l, ll r, int k)
{
    if (l <= L && R <= r)
    {
        a[aSz][0] = L;
        a[aSz][1] = k;
        aSz++;
        return;
    }
    if (l >= R || L >= r) return;
    ll M = L + (R - L) / 2;
    goA(L, M, l, r, k - 1);
    goA(M, R, l, r, k - 1);
}

void goB(ll L, ll R, ll l, ll r, int k)
{
    if (l <= L && R <= r)
    {
        b[bSz][0] = L;
        b[bSz][1] = k;
        bSz++;
        return;
    }
    if (l >= R || L >= r) return;
    ll M = L + (R - L) / 2;
    goB(L, M, l, r, k - 1);
    goB(M, R, l, r, k - 1);
}

ll getAr(ll r)
{
    return (r * (r + 1) / 2) % MOD;
}
ll getAr(ll l, ll r)
{
    return sub(getAr(r), getAr(l));
}

ll solve(ll x1, int log1, ll x2, int log2, ll k)
{
    if (log1 < log2)
    {
        swap(x1, x2);
        swap(log1, log2);
    }
    ll s = x1 ^ (x2 - (x2 & ((1LL << log1) - 1)));
    ll f = s + (1LL << log1);
    f = min(f, k);
    if (f <= s) return 0;
    return (getAr(s, f) << log2) % MOD;
}

ll solve(ll k)
{
    ll ans = 0;
    for (int i = 0; i < aSz; i++)
        for (int j = 0; j < bSz; j++)
        {
            ans = add(ans, solve(a[i][0], a[i][1], b[j][0], b[j][1], k));
            //printf("%d %d %d %d --- %d\n", a[i][0], a[i][1], b[j][0], b[j][1], ans);
        }
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x1, y1, x2, y2, k;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        x1--;
        y1--;
        aSz = bSz = 0;
        goA(0, C, x1, x2, LOG);
        goB(0, C, y1, y2, LOG);
        printf("%lld\n", solve(k));
    }

    return 0;
}