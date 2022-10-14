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
string s;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%I64d", &x);
        m = 0;
        while (x != 1) {
            m++;
            x /= 2;
        }
        a[m]++;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        int ans = 0;
        for (int j = 30; j >= 0; j--) {
            if (a[j] > 0 && x >= (1<<j)) {
                ll s = (x>>j);
                ll m = min(s, a[j]);
                ans += m;
                x -= m*(1<<j);
            }
        }
        if (x == 0)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}