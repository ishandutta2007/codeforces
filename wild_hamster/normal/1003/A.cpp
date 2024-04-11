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
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
ll a[1000005];
map<ll,ll> f;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f[x]++;
        ans = max(ans, f[x]);
    }
    cout << ans << endl;
    return 0;
}