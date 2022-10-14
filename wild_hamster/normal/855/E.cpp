#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,r,timer,mx;
ll a[100500], b[100500], pre[15][65][1050];
vector<ll> f1, f2;
ll check(ll x, ll base)
{
    ll c[10];
    for (int i = 0; i < 10; i++)
        c[i] = 0;
    while (x)
    {
        c[x%base] ^= 1;
        x/=base;
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++)
        ans += c[i];
    if (ans == 0)
        return 1;
    return 0;
}
int main() {
    for (i = 2; i <= 10; i++)
    {
        pre[i][0][0] = 1;
        for (j = 0; j < 60; j++)
            for (l = 0; l < (1<<i); l++)
                for (k = 0; k < i; k++)
                    pre[i][j+1][l^(1<<k)] += pre[i][j][l];
    }
    //freopen("input.txt","r",stdin);
    cin >> q;
    for (int ix = 0; ix < q; ix++)
    {
        cin >> n >> l >> r;
        if (l == r)
        {
            cout << check(l, n) << endl;
            continue;
        }
        f1.clear();
        f2.clear();
        x = l;
        while (x)
        {
            f1.push_back(x%n);
            x /= n;
        }
        x = r;
        while (x)
        {
            f2.push_back(x%n);
            x /= n;
        }
        ll sz = max((int)f1.size(), (int)f2.size());
        while(f1.size() < sz)
            f1.push_back(0);
        while(f2.size() < sz)
            f2.push_back(0);
        reverse(f1.begin(), f1.end());
        reverse(f2.begin(), f2.end());
        ll wasted = 0;
        ll mask = 0;
        i = 0;
        while (f1[i] == f2[i] && i < sz)
        {
            mask ^= (1<<f1[i++]);
        }
        if (i > 0)
            wasted = 1;
        ll ans = 0;
        for (j = f1[i]+1; j < f2[i]; j++)
        {
            ll lft = sz-i-1;
            ans += pre[n][lft][mask^(1<<j)];
        }
        ll ii = i;
        ll mmask = mask;
        if (wasted || f1[i] > 0)
        {
            mask ^= (1<<f1[i]);
            wasted = 1;
        }
        i++;
        for (; i < sz; i++)
        {
            ll lx = f1[i];
            if (lx > 0)
                wasted = 1;
            for (j = lx+1; j < n; j++)
            {
                ans += pre[n][sz-i-1][mask^(1<<j)];
            }
            if (wasted)
                mask ^= (1<<lx);
        }
        mask = mmask;
        i = ii;
        mask ^= (1<<f2[i++]);
        for (; i < sz; i++)
        {
            ll rx = f2[i];
            for (j = 0; j < rx; j++)
            {
                ans += pre[n][sz-i-1][mask^(1<<j)];
            }
            mask ^= (1<<rx);

        }
        ans += check(l,n) + check(r,n);
        cout << ans << endl;
    }
    return 0;
}