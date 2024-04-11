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

const ll MOD = (ll)1e9 + 7;

ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
    if (p == 0) return 1;
    if (p == 2) return mult(x, x);
    if (p & 1) return mult(bin_pow(x, p - 1), x);
    return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}

const int N = 200100;
const int B = 500;
const int P = (int)1e6 + 5;
int d[P];
int pr[P];
int prSz;
ll ans[N];
ll mp[P][2];
int bal[P];
vector<int> divs[N];
ll a[N];
ll pref[N];
int n, q;
int L, R;
ll value;

struct Query
{
    int id;
    int l, r;

    Query() : id(), l(), r() {}
    Query(int _id, int _l, int _r) : id(_id), l(_l), r(_r) {}

    bool operator < (const Query &Q) const
    {
        return r < Q.r;
    }
};
vector<Query> buckets[B];

void precalc()
{
    for (int i = 0; i < P; i++)
        d[i] = -1;
    for (int x = 2; x < P; x++)
    {
        if (d[x] != -1) continue;
        pr[prSz++] = x;
        mp[x][0] = mult(x - 1, rev(x));
        mp[x][1] = rev(mp[x][0]);
        for (int y = x; y < P; y += x)
            if (d[y] == -1)
                d[y] = x;
    }
    return;
}

void read()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    pref[0] = 1;
    for (int i = 0; i < n; i++)
        pref[i + 1] = mult(pref[i], a[i]);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while(x > 1)
        {
            int p = d[x];
            divs[i].push_back(p);
            while(x % p == 0) x /= p;
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        ans[i] = mult(pref[r], rev(pref[l]));
        int x = l / B;
        buckets[x].push_back(Query(i, l, r));
    }
    for (int i = 0; (i - 1) * B < n; i++)
        sort(buckets[i].begin(), buckets[i].end());
    return;
}

void clear()
{
    value = 1;
    for (int i = 0; i < prSz; i++)
        bal[pr[i]] = 0;
    return;
}

void addNum(int id)
{
    for (int p : divs[id])
    {
        if (bal[p] == 0)
            value = mult(value, mp[p][0]);
        bal[p]++;
    }
}
void removeNum(int id)
{
    for (int p : divs[id])
    {
        bal[p]--;
        if (bal[p] == 0)
            value = mult(value, mp[p][1]);
    }
}

void solve(int b)
{
    clear();
    R = L = buckets[b][0].l;
    for (Query Q : buckets[b])
    {
        while(R < Q.r)
        {
            addNum(R);
            R++;
        }
        if (L < Q.l)
        {
            while(L < Q.l)
            {
                removeNum(L);
                L++;
            }
        }
        else
        {
            while(L > Q.l)
            {
                L--;
                addNum(L);
            }
        }
        ans[Q.id] = mult(ans[Q.id], value);
    }
    return;
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    freopen ("err.txt", "w", stderr);
#endif

    precalc();
    read();
    for (int i = 0; (i - 1) * B < n; i++)
        if (!buckets[i].empty())
            solve(i);
    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}