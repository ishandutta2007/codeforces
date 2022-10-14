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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y, INF;
ll a[1200005], d[1205000];
set<ll> f;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    INF = (2LL*(ll)1e+18)+3;
    i = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    i = 0;
    ll sz = 0;
    while (i < n) {
        x = i;
        while (a[i] == 1 && i < n)
            i++;
        d[sz++] = i-x;
        if (i == n)
            break;
        d[sz++] = a[i++];
        if (i == n) {
            d[sz++] = 0;
            break;
        }
    }
    ll ans = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++)
            if (a[i] == 1)
                ans++;
    }
    /*for (int i = 0; i < sz; i++) {
        cout << d[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < sz/2; i++) {
        ll curi = i*2+1;
        ll onecntst = d[i*2];
        ll sum = 0;
        ll prod = 1;
        for (int j = 0; j < 65; j++) {
            ll curj = curi + j*2;
            if (curj >= sz)
                break;
            if (prod > INF/d[curj] + 2)
                break;
            prod *= d[curj];
            sum += d[curj];
            //cout << curi << " " << curj << " " << prod << " " << onecntst << " " << d[curj+1] << " " << sum << endl;
            //cout << i << " " << j << " " << ans << endl;
            if (prod % k == 0 && prod / k >= sum && prod / k <= sum + onecntst + d[curj+1]) {
                ll lft = onecntst;
                ll rgt = d[curj+1];
                ll diff = prod/k - sum;
                if (diff <= min(lft, rgt)) {
                    ans += diff+1;
                } else
                if (diff <= max(lft, rgt)) {
                    ans += min(lft, rgt) + 1;
                } else {
                    ans += lft+rgt+1-diff;
                }
            }
            //cout << i << " " << j << " " << ans << endl;
            sum += d[curj+1];
        }
    }
    cout << ans << endl;
    return 0;
}