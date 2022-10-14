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
#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans, sz,d;
ll a[100500], b[100500];
vector<ll> f;
set<ll> g;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (g.find(a[i]) == g.end()) {
            b[i] = 1;
            g.insert(a[i]);
        }
    }
    g.clear();
    for (int i = n-1; i >= 0; i--) {
        if (b[i]) {
            ans += (int)(g.size());
        }
        g.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}