#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
const int INF = 1000*1000*1000;
ll n,m,k,x,y;
pii a[1005000];
ll nx[1005000], pr[1005000];
ll cnt(ll l, ll r) {
    if (l > r)
        swap(l, r);
    ll sum = l/(k-1);
    ll ans = 0;
    ll st = 1;
    ans += (st + (st+sum*(k-1)))*(sum+1) / 2;
    l -= sum*(k-1);
    r -= sum*(k-1);
    st += sum*(k-1);

    ll dots_l = l;
    ll dots_r = min(r, k-1);
    st -= (k-1-dots_l);
    st -= (k-1-dots_r);
    st += k-1;
    if (st > 0)
        ans += st;
    else
        return ans;
    r -= dots_r;
    sum = r/(k-1);
    ans += sum*st;
    r -= sum*(k-1);
    st -= (k-1-r);
    if (st > 0)
        ans += st;
    else
        return ans;
    st -= (k-1);
    if (st <= 0)
        return ans;
    sum = st/(k-1);
    ans += (st+(st-sum*(k-1)))*(sum+1)/2;
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i].X = x;
        a[i].Y = i;
        nx[i] = i+1;
        pr[i] = i-1;
    }
    sort(a+1, a+n+1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll val = a[i].X;
        ll pos = a[i].Y;
        ll np = nx[pos];
        ll pp = pr[pos];
        ll l = pos-pp-1;
        ll r = np-pos-1;
        //cout << i << " " << val << " " << pos << " " << l << " " << r << endl;
        ans += (cnt(l, r)-1)%MOD*val%MOD;
        nx[pr[pos]] = np;
        pr[nx[pos]] = pp;
    }
    cout << ans%MOD << endl;
	return 0;
}