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
ll i,j,k,z,q,timer, v,x,y,xx, yy,INF, sz,n,m, cnt;
ll a[100500], b[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    ll ans = n;
    for (int i = 0; i < n; i++)
        ans += max(a[i], b[i]);
    cout << ans << endl;
    return 0;
}