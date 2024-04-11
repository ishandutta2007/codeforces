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
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
ll a[100500], b[100500];
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2)
        return x * tmp % MOD;
    return tmp;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b,a%b);
}

ll get(ll x) {
    for (int i = 2; i < 30; i++) {
        if ((1<<i)-1 >= x) {
            return (1<<i)-1;
        }
    }
}

ll pat[24] = {1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    /*for (int ii = 2; ii <= 25; ii++) {
        ll i = (1<<ii) - 1;
            ll ans = 0;
        for (int j = 1; j < i; j++) {
            ll x = gcd((i^j), (i&j));
            ans = max(ans, x);
        }
        cout << ans << ",";
    }*/
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n;
        ll x = get(n);
        if (x == n) {
            for (int j = 2; j < 30; j++) {
                if (x == (1<<j)-1) {
                    cout << pat[j-2] << endl;
                    break;
                }
            }
        } else {
            cout << x << endl;
        }
    }
    return 0;
}