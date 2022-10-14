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
ll a[100500];
ll f(ll x) {
    ll ans = 0;
    while (x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n < 10) {
        cout << n << endl;
        return 0;
    }
    a[0] = 1;
    for (int i = 1; i < 15; i++)
        a[i] = a[i-1]*10;
    for (int i = 1; i < 15; i++) {
        if (a[i]-1 > n) {
            k = i-1;
            break;
        }
    }
    cout << f(a[k]-1)+f(n-(a[k]-1)) << endl;

    return 0;
}