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
//#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx;
ll a[100500];
vector<pii> f[2];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    ll ans1 = 0, ans2 = 0, ans = 0;
    for (i = 0; i < n; i++)
    {
        ll x,y,z;
        scanf("%I64d %I64d %I64d",&x,&y,&z);
        if (y > z)
        {
            f[0].push_back(mp(y-z, x));
            ans1 += x;
            ans += x*y;
        } else
        {
            f[1].push_back(mp(z-y, x));
            ans2 += x;
            ans += x*z;
        }
    }
    ll sum = ans1+ans2;
    sum = ((sum-1)/k+1)*k;
    ll val1 = (ans1==0?0:((ans1-1)/k+1)*k);
    ll val2 = sum-val1;
    ll dif = 0;
    sort(f[0].begin(), f[0].end());
    sort(f[1].begin(), f[1].end());
    ll diff = (ans2-val2);
    if (val1 >= 0 && val2 >= 0)
    {
        for (i = 0; i < f[1].size(); i++)
        if (diff > 0)
        {
            ll to_use = min(diff, f[1][i].Y);
            dif += to_use*f[1][i].X;
            diff -= to_use;
        }
    }
    ll res = ans-dif;
    val1 -= k;
    val2 += k;
    diff = (ans1-val1);
    dif = 0;
    if (val1 >= 0 && val2 >= 0)
    {
        for (i = 0; i < f[0].size(); i++)
        if (diff > 0)
        {
            ll to_use = min(diff, f[0][i].Y);
            dif += to_use*f[0][i].X;
            diff -= to_use;
        }
    }
    res = max(res, ans-dif);
    cout << res << endl;
    return 0;
}