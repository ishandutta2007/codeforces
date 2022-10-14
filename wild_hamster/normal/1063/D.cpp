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
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
vector<pii> f, f1;
ll solve(ll n, ll l, ll r, ll k, ll id) {
    ll C1 = 2*(r-l+1)-k;
    ll C2 = k - (r-l+1);
    ll m1 = -C1/(2*n) - 5;
    ll m2 = C2/n - 5;
    //cout << C1 << " " << C2 << endl;
    while (2*m1*n + C1 < 0)
        m1++;
    while (C2 - m2*n - n >= 0)
        m2++;
    //cout << m1 << " " << m2 << endl;
    if (m1 > m2) {
        return -1;
    }

    ll ans = -1;
    if (m1 == 0) {
        ll diff = k-(r-l+1);
        if (diff >= id && diff <= r-l+1)
            ans = diff + n-(r-l+1);
        m1++;
    }
    //cout << m1 << " " << m2 << endl;
    for (ll i = m1; i <= m2; i++) {
        ll T = k - (r-l+1);
        ll x, y;
        ll K = (T/i - T%i - 2*n + (r-l+1) + i)/(i+1);
        y = T/i-K-T%i-i*K - n;
        x = (T - y*i - n*i)/(i+1);
        //cout << x << " " << y << endl;
        if (x >= id && x <= r-l+1 && y >= 0 && y <= n-(r-l+1))
            ans = max(ans, x+y);
    }

    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (l > r) {
        r += n;
    }
    if (n >= 10000) {
        ll ans1 = solve(n,l,r,k,0);
        ll ans2 = solve(n,l,r,k+1,1);
    //cout << ans1 << " " << ans2 << endl;
        cout << max(ans1, ans2) << endl;
    } else {
        ll ans = -1;
        for (int i = 0; i <= r-l+1; i++)
            for (int j = 0; j <= n-(r-l+1); j++)
                if (k-(r-l+1)-i >= 0 && (k-(r-l+1)-i)%(i+j+n) == 0) {
                    ans = max(ans, 0LL+i+j);
                }
        k++;
        for (int i = 1; i <= r-l+1; i++)
            for (int j = 0; j <= n-(r-l+1); j++)
                if (k-(r-l+1)-i >= 0 && (k-(r-l+1)-i)%(i+j+n) == 0) {
                    ans = max(ans, 0LL+i+j);
                }
        cout << ans << endl;
    }
    return 0;
}