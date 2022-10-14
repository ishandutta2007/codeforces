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
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll p, q, b;
        scanf("%I64d %I64d %I64d", &p, &q, &b);
        ll g = gcd(p, q);
        p /= g;
        q /= g;
        ll cnt = 0;
        while (1) {
            ll x = gcd(q, b);
            if (x == 1)
                break;
            cnt++;
            while (q % x == 0)
                q /= x;
        }
        assert(cnt <= 5);
        if (q == 1) {
            printf("Finite\n");
        } else {
            printf("Infinite\n");
        }
    }
    return 0;
}