#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define mp make_pair

const ll INF = (ll)1e18;
const int N = (int)150000 + 100;

inline ll myMin(ll a, ll b)
{
    return (a < b ? a : b);
}

inline ll myMax(ll a, ll b)
{
    return (a > b ? a : b);
}

struct Queue
{
    pll fst[N];//pair<val, max>!!!
    pll scnd[N];
    int fstSz, scndSz;
    void build()
    {
        fstSz = scndSz = 0;
    }
    inline ll getMax()
    {
        ll ans = -INF;
        if (fstSz > 0)
            ans = myMax(ans, fst[fstSz - 1].Y);
        if (scndSz > 0)
            ans = myMax(ans, scnd[scndSz - 1].Y);
        return ans;
    }
    inline void insert(ll val)
    {
        fst[fstSz] = mp(val, myMax((fstSz == 0 ? -INF : fst[fstSz - 1].Y), val));
        fstSz++;
    }
    inline bool empty()
    {
        return (fstSz == 0 && scndSz == 0);
    }
    inline void pop()
    {
        if (scndSz > 0)
            scndSz--;
        else
        {
            while (fstSz > 0)
            {
                ll cur = fst[fstSz - 1].X;
                scnd[scndSz] = mp(cur, myMax((scndSz == 0 ? -INF : scnd[scndSz - 1].Y), cur));
                scndSz++;
                fstSz--;
            }
            scndSz--;
        }
    }
} que;

inline int myAbs(int a)
{
    return (a < 0 ? -a : a);
}


int A[N], B[N], T[N];
ll dp[N];
ll newDp[N];

int main()
{
    que.build();
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &A[i], &B[i], &T[i]);
        A[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        for (int s = 0; s < n; s++)
        {
            dp[s] += B[i] - myAbs(s - A[i]);
        }
        ll k = myMin((ll)(i == m - 1 ? 0 : T[i + 1] - T[i]) * (ll)d, (ll)n);

        for (int s = 0; s < n; s++)
        {
            newDp[s] = myMax(dp[s], que.getMax());
            que.insert(dp[s]);
            if (s - k >= 0)
                que.pop();
        }
        que.fstSz = que.scndSz = 0;
        for (int s = n - 1; s >= 0; s--)
        {
            newDp[s] = myMax(newDp[s], que.getMax());
            que.insert(dp[s]);
            if (s + k < n)
                que.pop();
        }
        que.fstSz = que.scndSz = 0;
        for (int s = 0; s < n; s++)
        {
            dp[s] = newDp[s];
        }
    }
    
    ll ans = -(ll)1e18;
    for (int i = 0; i < n; i++)
        ans = myMax(ans, dp[i]);
    cout << ans;
    return 0;
}