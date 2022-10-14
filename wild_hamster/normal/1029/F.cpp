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
ll n,m,k,x,y;
ll a[100500], b[100500], minx[105000];
vector<pii> f;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    x = n+m;
    ll min1 = (ll)1e+18, min2 = (ll)1e+18;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            f.push_back(mp(i, n/i));
        }
    }

    for (ll i = 1; i*i <= m; i++) {
        if (m%i == 0) {
            f.push_back(mp(i, m/i));
        }
    }
    sort(f.begin(), f.end());
    min1 = (ll)1e+18;
    minx[0] = min1;
    for (int i = 0; i < f.size(); i++) {
        min1 = min(min1, f[i].Y);
        minx[i+1] = min1;
    }
    ll ans = (ll)1e+18;
    for (ll i = 1; i*i <= x; i++)
        if (x%i == 0) {
            ll val = x/i;
            ll flag = 0;
            ll pos = upper_bound(f.begin(), f.end(), mp(i, (ll)1e+18))-f.begin();

            if (minx[pos] <= val) {
                ans = min(ans, i+val+i+val);
            }
        }
    cout << ans << endl;
	return 0;
}