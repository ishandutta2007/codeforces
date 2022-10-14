#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
ll w[200500];
ll used[100500];
vector<ll> f;
set<ll> g;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        w[i] = upper_bound(b, b+n, a[i]-1) - b;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        if (a[x] > a[y]) {
            w[x]--;
        }
        if (a[y] > a[x])
            w[y]--;
    }
    for (int i = 0; i < n; i++)
        cout << w[i] << " ";
    return 0;
}