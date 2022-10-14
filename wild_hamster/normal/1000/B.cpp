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
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,y,INF, ans;
ll a[1200005], b[1205000], sa[1205000][2];
map<string, ll> x;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[0] = a[0];
    for (int i = 0; i < n-1; i++)
        b[i+1] = a[i+1] - a[i];
    b[n] = m - a[n-1];
    for (int i = 0; i <= n; i++) {
        sa[i+1][0] = sa[i][0];
        sa[i+1][1] = sa[i][1];
        sa[i+1][i%2] += b[i];
    }
    ll ans = sa[n+1][0];
    for (int i = 0; i <= n; i++) {
        ll cur = sa[i][0];
        if (b[i] < 2)
            continue;
        cur += b[i]-1;
        cur += sa[n+1][1] - sa[i+1][1];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}